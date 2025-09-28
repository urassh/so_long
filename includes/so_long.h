/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:50:38 by urassh            #+#    #+#             */
/*   Updated: 2025/09/10 15:50:40 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "map.h"
# include "player_controller.h"

/* ************************************************************************** */
/*                               KEY CODES                                   */
/* ************************************************************************** */

/* Movement Keys */
# define KEY_W          13
# define KEY_A          0
# define KEY_S          1
# define KEY_D          2
# define KEY_UP         126
# define KEY_DOWN       125
# define KEY_LEFT       123
# define KEY_RIGHT      124

/* Control Keys */
# define KEY_ESC        53
# define KEY_SPACE      49
# define KEY_ENTER      36
# define KEY_TAB        48

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
