/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bot.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:39:44 by rteles            #+#    #+#             */
/*   Updated: 2023/03/29 18:10:32 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BOT_HPP
# define BOT_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sys/poll.h>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <algorithm>
#include <vector>
#include "Msg.hpp"

#define BUFFER_SIZE 1024

class Bot
{
    private:
        std::string _name;
        std::string _hostname;
		std::string	_port;
		std::string	_password;
        int			_socket;
		pollfd		*pollEvents;
        std::map<std::string, std::map<std::string, int> > _players;

        Bot(void);

    public:
		Bot(std::string host, char * port, std::string password, std::string name);
        Bot(std::string const & type);
        Bot( Bot const & src);
        
        ~Bot(void);

        Bot & operator=(Bot const & rhs);

        void    authenticate(void);
		void	run(void);
		int 	recive(void);
		int 	response(std::string message);
		void	sendMessage(std::string const command, std::string const message);
		void	privateMessage(std::string message);
        void    debug(std::string message, std::string callBack, std::string user, std::string channel);
        void    quit(void);

        //Games
        void        game(std::string user, std::string channel, std::string message, std::string game, std::string choise);
        std::string	rockPapperScissors(std::string nick, std::string choise);
        std::string guessNumber(std::string nick, std::string choise);

        //Player [EXP]
        std::map<std::string, int>  &addPlayer(std::string nick);
        void                        setPlayer(std::string nick, bool isWin, int exp);
        std::string                 showLeaderBoard(void);

};

static std::string convertToInt(int input)
{
    std::ostringstream stream;
    
	stream << input;

    std::string nbr = stream.str();
	
	return nbr;
}

#endif