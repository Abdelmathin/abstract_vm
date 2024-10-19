/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   abstract_vm.hpp                                    :+:      :+:    :+:    */
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

#pragma once

#include <iostream>
#include <map>

#define CHARACTER_SEMICOLON          ';'
#define CHARACTER_CARRIAGE_RETURN    '\r'
#define CHARACTER_LINE_FEED          '\n'
#define CHARACTER_SPACE              ' '
#define CHARACTER_TAB                '\t'
#define CHARACTER_LEFT_PARENTHESIS   '('
#define CHARACTER_RIGHT_PARENTHESIS  ')'
#define CHARACTER_DOT                '.'

#define TOKEN_TYPE_UNKNOWN           (0 << 0)
#define TOKEN_TYPE_COMMENT           (1 << 0)
#define TOKEN_TYPE_WORD              (1 << 1)
#define TOKEN_TYPE_SEMICOLON         CHARACTER_SEMICOLON
#define TOKEN_TYPE_CARRIAGE_RETURN   CHARACTER_CARRIAGE_RETURN
#define TOKEN_TYPE_LINE_FEED         CHARACTER_LINE_FEED
#define TOKEN_TYPE_SPACE             CHARACTER_SPACE
#define TOKEN_TYPE_TAB               CHARACTER_TAB
#define TOKEN_TYPE_LEFT_PARENTHESIS  CHARACTER_LEFT_PARENTHESIS
#define TOKEN_TYPE_RIGHT_PARENTHESIS CHARACTER_RIGHT_PARENTHESIS

#define IS_DIGIT(c)        (('0' <= c) && (c <= '9'))
#define IS_SPACE(c)        ((c == ' ') || (c == '	'))
#define IS_VARSTART(c)     ((c == '_') || (('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z')))
#define IS_VARCHAR(c)      (IS_DIGIT(c) || IS_VARSTART(c))

namespace abstract_vm
{
	enum eOperandType
	{
		Int8   = (1 << 0),
		Int16  = (1 << 1),
		Int32  = (1 << 2),
		Float  = (1 << 3),
		Double = (1 << 4)
	};
	const std::string crlf = "\r\n";
	std::string ltrim(std::string str);
	std::string rtrim(std::string str);
	std::string trim(std::string  str);
	std::string ltrim(std::string str, std::string charset);
	std::string rtrim(std::string str, std::string charset);
	std::string trim(std::string  str, std::string charset);
}
