//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "client.h"
using namespace std;
Define_Module(Client);

void Client::initialize()
{
    // TODO - Generated method body
    if(strcmp(getName(),"pc1")==0)
    {
        string plaintext="attackatdawn";
        int message_size=plaintext.size();
         string key="hello";
         int key_size=key.size();
         int total_keySize=message_size-key_size;
         string new_key = key + plaintext.substr(0,total_keySize);
         char encrypt[message_size+1];
         for(int i=0; i<message_size;i++)
         {
             char ch=(((plaintext[i]-'a')+(new_key[i]-'a'))%26)+'a';
             encrypt[i]=ch;
         }
         encrypt[message_size] = '\0';
         cMessage *newmsgs=new cMessage(encrypt);
          send(newmsgs,"out");
    }
}


void Client::handleMessage(cMessage *msg)
{

}

