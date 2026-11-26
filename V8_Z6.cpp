#include <iostream>
#include <string>
#include <vector>

class Notification {
protected:                    //recipient je bio private, mora bit protected
	std::string recipient;                  
public:
	Notification(const std::string& r) : recipient(r) {} //destruktor nije virtualan pa je delete preskocio ~Email
	virtual ~Notification() { std::cout << "~Notification\n"; }
	
	virtual void send() const { std::cout << "obavijest za " << recipient << '\n'; } //send nije bila virtualan pa je poziv uvijek birao ovaj send
};

class Email : public Notification {
	std::string subject;
public:		//nedostajao je poziv Notification(r) u listi inicijalizacije
	Email(const std::string& r, const std::string& s) : Notification(r), subject(s) {}
	~Email() override { std::cout << "~Email\n"; }
	void send() const override { std::cout << "email za " << recipient << ": " << subject << '\n'; }
};

//bilo je privatno pa Sms* nebi postao Notification*
class Sms : public Notification {
	std::string text;
public:
	Sms(const std::string& r, const std::string& t) : Notification(r), text(t) {}
	void send() const override { std::cout << "SMS za " << recipient << ": " << text << '\n'; }
};

//kopirao samo Notification dio pa se zvao originalni send bez poruke 
void send_twice(const Notification& n)
{
	n.send();
	n.send();
}

int main()
{
	std::vector<Notification*> inbox;
	inbox.push_back(new Email("Ana", "Kolokvij u petak"));
	inbox.push_back(new Sms("Marko", "Kasnim 10 min"));

	for (Notification* n : inbox)
		n->send();
	std::cout << "---\n";
	send_twice(*inbox[1]);
	std::cout << "---\n";

	for (Notification* n : inbox)
		delete n;
	return 0;
}

/*
Ocekivani ispis:

	email za Ana: Kolokvij u petak
	SMS za Marko: Kasnim 10 min
	---
	SMS za Marko: Kasnim 10 min
	SMS za Marko: Kasnim 10 min
	---
	~Email
	~Notification
	~Notification
*/