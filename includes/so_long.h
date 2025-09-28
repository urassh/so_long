/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:50:38 by urassh            #+#    #+#             */
/*   Updated: 2025/09/28 18:28:30 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "map.h"
# include "player_controller.h"

/* ************************************************************************** */
/*                               KEY CODES                                   */
/* ************************************************************************** */

# ifdef __APPLE__
# define KEY_W          13
#   define KEY_A          0
#   define KEY_S          1
#   define KEY_D          2
#   define KEY_UP         126
#   define KEY_DOWN       125
#   define KEY_LEFT       123
#   define KEY_RIGHT      124

    /* Control Keys (macOS) */
#   define KEY_ESC        53
#   define KEY_SPACE      49
#   define KEY_ENTER      36
#   define KEY_TAB        48

# else
#   include <X11/keysym.h>

    /* Movement Keys (Linux / X11) */
#   define KEY_W          XK_w
#   define KEY_A          XK_a
#   define KEY_S          XK_s
#   define KEY_D          XK_d
#   define KEY_UP         XK_Up
#   define KEY_DOWN       XK_Down
#   define KEY_LEFT       XK_Left
#   define KEY_RIGHT      XK_Right

    /* Control Keys (Linux / X11) */
#   define KEY_ESC        XK_Escape
#   define KEY_SPACE      XK_space
#   define KEY_ENTER      XK_Return
#   define KEY_TAB        XK_Tab
# endif

/* ************************************************************************** */
/*                              EVENT CODES                                  */
/* ************************************************************************** */

/* Input Events */
# define ON_KEY_DOWN            2
# define ON_KEY_UP              3
# define ON_MOUSE_DOWN          4
# define ON_MOUSE_UP            5
# define ON_MOUSE_MOVE          6
# define ON_MOUSE_ENTER         7
# define ON_MOUSE_EXIT          8
# define ON_FOCUS_IN            9
# define ON_FOCUS_OUT           10
# define ON_EXPOSE              12
# define ON_CONFIGURE_NOTIFY    22
# define ON_DESTROY             17

/* X11 Event Masks */
# define MASK_NO_EVENT          0L
# define MASK_KEY_PRESS         1L
# define MASK_KEY_RELEASE       2L
# define MASK_BUTTON_PRESS      4L
# define MASK_BUTTON_RELEASE    8L
# define MASK_ENTER_WINDOW      16L
# define MASK_LEAVE_WINDOW      32L
# define MASK_POINTER_MOTION    64L
# define MASK_EXPOSURE          32768L

#endif
