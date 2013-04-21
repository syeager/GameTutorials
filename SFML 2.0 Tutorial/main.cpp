// Video: 30
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

using namespace std;

int main1()
{
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	sf::TcpSocket socket;
	char connectionType, mode;
	char buffer[2000];
	size_t received;
	string text = "Connected to: ";

	cout << "Connection Type: ";
	cin >> connectionType;

	if (connectionType == 's')
	{
		sf::TcpListener listener;
		listener.listen(2000);
		listener.accept(socket);
		text += "server";
		mode = 's';
	}
	else if (connectionType == 'c')
	{
		socket.connect(ip, 2000);
		text += "client";
		mode = 'r';
	}

	socket.send(text.c_str(), text.length()+1);
	socket.receive(buffer, sizeof(buffer), received);
	cout<<buffer<<endl;

	bool done = false;

	while (!done)
	{
		if (mode == 's')
		{
			getline(cin, text);
			socket.send(text.c_str(), text.length()+1);
			mode = 'r';
		}
		else
		{
			socket.receive(buffer, sizeof(buffer), received);
			if (received > 0)
			{
				cout<<"Received: " << buffer<<endl;
				mode = 's';
			}
		}
	}

	system("pause");

	return 0;
} // end main