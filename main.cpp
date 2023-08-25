#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <zmq.hpp>
#include "service.pb.h"

int generateUniqueId(){

	std::srand(time(NULL));
	return rand();
}

void sendStopMessage(zmq::socket_t &socket){

	ServiceMassage message;
	message.set_command(ServiceMessage::STOP);
	message.set_id(generateUniqueId());

	zmq::message_t zmqMessage(message.ByteSiseLong());
	message.SerializeToArray(zmqMessage.data(), zmqMessage.size());

	socket.send(zmqMessage, zmq::send_flags::none);
}

void recieveMessage(zmq::socket_t &socket, vector<int> &ids){

	zmq::message_t zmqMessage;
	secket.recv(Message, zmq::recv_flags::none);

	ServiceMessage message;
	message.ParseFromArray(zmqMessage.data(), zmqMessage.size());

	if(message.command()==ServiceMessage::STOP){
		ids.erase(remove(ids.begin, ids.end(), message.id()), ids.end());
	}




int main(int argc, char* argv[]){

	bool isMaster=true;

	if(argc>1 && string(argv[1] == "-k"){
		isMaster=false;
	}

	vector<int> ids;
	zmq::context_t context(1);
	zmq::socket_t socket(context, zmq::socket_type::req);

	if(isMaster){
		socket.bind("tcp://*:5555");
		ids.push_back(generateUniqueId());
	}else{
		socket.connect("tcp://localhost:5555");
		sendStopMessage(socket);
		return 0;
	}

	while(true){

		if(isMaster){
			ids.push_back(generateUniqueId());
			std::cout<<"IDs: ";
			for(int id:ids){
				std::cout<<id<<"\t";
			}
			std::cout<<std::endl;

			this_thread::sleep_for(chrono::seconds(1));
			sendStopMessage(socket);
		}else{
			receiveMessage(socket, ids);
		}
	}

	return 0;
}

