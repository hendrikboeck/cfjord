/******************************************************************************/
/* cfjord                                                                     */
/* Copyright (C) 2021  Hendrik Boeck <hendrikboeck.dev@protonmail.com>        */
/*                                                                            */
/* This program is free software: you can redistribute it and/or modify       */
/* it under the terms of the GNU General Public License as published by       */
/* the Free Software Foundation, either version 3 of the License, or          */
/* (at your option) any later version.                                        */
/*                                                                            */
/* This program is distributed in the hope that it will be useful,            */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of             */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              */
/* GNU General Public License for more details.                               */
/*                                                                            */
/* You should have received a copy of the GNU General Public License          */
/* along with this program.  If not, see <http://www.gnu.org/licenses/>.      */
/******************************************************************************/

#ifndef _CFJORD_TYPES_H
#define _CFJORD_TYPES_H

#include <stdint.h>

typedef float  float32_t;
typedef double float64_t;

enum _bool_t { false, true };
typedef enum _bool_t bool_t;

typedef void*       vptr_t;
typedef signed char byte_t;

#endif  // _CFJORD_TYPES_H