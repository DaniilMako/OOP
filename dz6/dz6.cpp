#include <iostream>
#include <string>

using namespace std;

void SendSms(const string& number, const string& message) {
	cout << "Send '" << message << "' to number " << number << endl;
}

void SendEmail(const string& email, const string& message) {
	cout << "Send '" << message << "' to e-mail " << email << endl;
}

class  INotifier {
public:
	virtual void Notify(const string& message) = 0;
};

class SmsNotifier : public INotifier {
public:
	SmsNotifier(const string& this_number) : number(this_number) {}

	void Notify(const string& message) override {
		SendSms(number, message);
	}

private:
	const string number;
};

class EmailNotifier : public INotifier {

public:
	EmailNotifier(const string& this_email) : email(this_email) {}

	void Notify(const string& message) override {
		SendEmail(email, message);
	}

private:
	const string email;
};

void Notify(INotifier& notifier, const string& message) {
	notifier.Notify(message);
}


int main() {
	SmsNotifier sms{ "+ 7-923-228-38-72" };
	EmailNotifier email{ "m.Filippov@g.nsu.ru" };
	Notify(sms, "I know lessons in C++");
	Notify(email, "And want the lesson one");
	return 0;
}