#include <iostream>
#include <string>
using namespace std;

string ReadText()
{
	string Text;
	cout << "please enter text? " << endl;
	getline(cin, Text);
	return Text;

}
string EncryptText(string Text , short EncryptionKey)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = char((int)Text[i] + EncryptionKey);
	}
	return Text;
}
string DecryptText(string Text, short EncryptionKey)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = char((int)Text[i] - EncryptionKey);
	}
	return Text;
}

int main()
{
	const short EncryptionKey = 2;

	string Text = ReadText();
	string TextAfterEncryotion = EncryptText(Text, EncryptionKey);
	string TextAfterDecryption = DecryptText(TextAfterDecryption, EncryptionKey);

	cout << "\nText Befor Encryption: " << Text;
	cout << "\nText After Encryption: " << TextAfterEncryotion;
	cout << "\nText After Decryption: " << TextAfterDecryption;
	return 0;
}