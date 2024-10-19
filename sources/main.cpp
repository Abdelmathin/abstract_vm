/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+      */
/*   By: ahabachi <abdelmathinhabachi@gmail.com>    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+            */
/*   Created: 2024/08/19 17:40:12 by ahabachi          #+#    #+#              */
/*   Updated: 2024/09/24 06:34:37 by ahabachi         ###   ########.fr        */
/*                                                                             */
/* **************************************************************************  */
/*                                                                             */
/*                                                                             */
/*                                                                             */
/*            _    _         _                  _    __     ____  __           */
/*           / \  | |__  ___| |_ _ __ __ _  ___| |_  \ \   / /  \/  |          */
/*          / _ \ | '_ \/ __| __| '__/ _` |/ __| __|  \ \ / /| |\/| |          */
/*         / ___ \| |_) \__ \ |_| | | (_| | (__| |_    \ V / | |  | |          */
/*        /_/   \_\_.__/|___/\__|_|  \__,_|\___|\__|    \_/  |_|  |_|          */
/*                                                                             */
/*                                                                             */
/*                                                                             */
/*                                                                             */
/*                                                                             */
/* **************************************************************************  */
/*                                                                             */
/*  █████████            ██████████         ██████████         ██████████      */
/*  ██     ██                    ██                 ██         ██      ██      */
/*         ██                    ██                 ██         ██      ██      */
/*         ██                    ██                 ██                 ██      */
/*         ██            ██████████         ██████████                 ██      */
/*         ██                    ██                 ██                 ██      */
/*         ██                    ██                 ██                 ██      */
/*         ██                    ██                 ██                 ██      */
/*      ████████         ██████████         ██████████                 ██      */
/*                                                                             */
/* **************************************************************************  */

# include "../include/abstract_vm.hpp"
# include "../include/Client.hpp"
#include <exception>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, const char **argv)
{
	if (argc < 2)
	{
		abstract_vm::Client client = abstract_vm::Client();
		client.setFdIn(STDIN_FILENO);
		client.setFdOut(STDOUT_FILENO);
		client.setFdErr(STDERR_FILENO);
		client.setEOS(";;");
		while ((client.isConnected()) && (client.read() > 0))
		{
			continue ;
		}
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		const int fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			std::cerr << argv[0] << ": " << argv[i] << ": No such file or directory" << std::endl;
			continue ;
		}
		try
		{
			abstract_vm::Client client = abstract_vm::Client();
			client.setFdIn(fd);
			client.setFdOut(STDOUT_FILENO);
			client.setFdErr(STDERR_FILENO);
			client.setEOS("exit");
			while ((client.isConnected()) && (client.read() > 0))
			{
				continue ;
			}
		}
		catch (const std::exception& xcp)
		{
			std::cerr << xcp.what() << std::endl;
		}
		close(fd);
	}
	return (0);
}
