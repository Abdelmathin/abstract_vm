/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:    */
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

namespace abstract_vm
{
    class IOperand
    {
        public:
            virtual int getPrecision( void )                           const = 0; // Precision of the type of the instance
            virtual eOperandType getType( void )                       const = 0; // Type of the instance
            virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
            virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
            virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
            virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
            virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
            virtual std::string const & toString( void )               const = 0; // String representation of the instance
            virtual ~IOperand( void ) {}
    };
}