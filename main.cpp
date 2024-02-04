#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "thread_manager.hpp"
#include "logging.hpp"

int SV_PORT = 25565;

int main()
{
	thread_man manager;
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr =
	{
		AF_INET, 
		htons(SV_PORT),
		0
	};

	log("This server is for testing and educational purposes, it will never be as good as vanilla/paper servers");
	if (bind(sock, (sockaddr *)&addr, sizeof(addr)) == -1)
	{
		log_err("Bind failed");
		return -1;
	}
	log("Server listening at ", "0.0.0.0:25566");
	while (1)
	{
		int client_fd = 0;
		listen(sock, 32);
		client_fd = accept(sockfd, nullptr, nullptr);
		std::thread cli_th(manage_sv, client_fd);
		cli_th.detach();
	}
}
