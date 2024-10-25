/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   abstract_vm.cpp                                    :+:      :+:    :+:    */
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

#ifndef __ABSTRACT_VM_SOURCES_ABSTRACT_VM
# define __ABSTRACT_VM_SOURCES_ABSTRACT_VM

# include "../include/abstract_vm.hpp"
# include <iostream>
# include <sstream>

std::string abstract_vm::ltrim(std::string str)
{
    return (abstract_vm::ltrim(str, "\v\f\t "));
}

std::string abstract_vm::rtrim(std::string str)
{
    return (abstract_vm::rtrim(str, "\v\f\t "));
}

std::string abstract_vm::trim(std::string str)
{
    return (abstract_vm::trim(str, "\v\f\t "));
}

std::string abstract_vm::ltrim(std::string str, std::string charset)
{
    std::string::size_type first = str.find_first_not_of(charset);
    if (first == std::string::npos)
    {
        return ("");
    }
    return (str.substr(first));
}

std::string abstract_vm::rtrim(std::string str, std::string charset)
{
    std::string::size_type last = str.find_last_not_of(charset);
    return (str.substr(0, last + 1));
}

std::string abstract_vm::trim(std::string str, std::string charset)
{
    return (abstract_vm::ltrim(abstract_vm::rtrim(str, charset), charset));
}

bool abstract_vm::isNumeric(const std::string s)
{
    if ((s.length() < 1) || ((s.length() > 1) && (s[0] == '0')))
        return (false);
    if ((s.length() < 2) && (s[0] == '-'))
        return (false);
    if ((s.length() > 2) && (s[0] == '-') && (s[1] == '0'))
        return (false);
    std::string::size_type i = (s[0] == '-');
    while ((i < s.length()) && std::isdigit(s[i]))
        i++;
    std::stringstream ss(s); double number = 0; ss >> number;
    return (!ss.fail() && ss.eof() && (i == s.length()));
}

bool abstract_vm::isDecimal(const std::string s)
{
    // TODO ...?
    if ((s.length() < 1) || ((s.length() > 1) && (s[0] == '0')))
        return (false);
    if ((s.length() < 2) && (s[0] == '-'))
        return (false);
    if ((s.length() > 2) && (s[0] == '-') && (s[1] == '0'))
        return (false);
    std::string::size_type i = (s[0] == '-');
    while ((i < s.length()) && std::isdigit(s[i]))
        i++;
    std::stringstream ss(s); double number = 0; ss >> number;
    return (!ss.fail() && ss.eof() && (i == s.length()));
}

#endif//!__ABSTRACT_VM_SOURCES_ABSTRACT_VM
