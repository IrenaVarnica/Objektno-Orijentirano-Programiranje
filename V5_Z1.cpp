#include <iostream>
#include <cassert>

class Volume
{
public:
    Volume();
    Volume(int l);

    void mute();
    void unmute();

    void up(int step = 10);
    void down(int step = 10);

    bool valid() const;
    int get() const;

    static int cap(int value);

private:
    int volume;
    int volumePreMute;
};

Volume::Volume() : Volume(50)
{
    assert(valid());
}

Volume::Volume(int l) : volume(cap(l)), volumePreMute(-1)
{
    assert(valid());
}

void Volume::up(int step)
{
    volume = cap(volume + step);
    assert(valid());
}

void Volume::down(int step)
{
    volume = cap(volume - step);
    assert(valid());
}

void Volume::mute()
{
    if (volumePreMute == -1)
    {
        volumePreMute = volume;
        volume = 0;
    }
    assert(valid());
}

void Volume::unmute()
{
    if (volumePreMute != -1)
    {
        volume = volumePreMute;
        volumePreMute = -1;
    }
    assert(valid());
}

int Volume::cap(int value)
{
    if (value < 0)
    {
        return 0;
    }

    if (value > 100)
    {
        return 100;
    }

    return value;
}

bool Volume::valid() const
{
    return (volume >= 0 && volume <= 100);
}

int Volume::get() const
{
    return volume;
}

int main()
{
    Volume v;
    std::cout << v.get() << '\n';
    v.up();
    v.up(60);
    std::cout << v.get() << '\n';
    v.mute();
    std::cout << v.get() << '\n';
    v.unmute();
    std::cout << v.get() << '\n';
    Volume w(-20);
    w.down();
    std::cout << w.get() << '\n';
    return 0;
}
