/*
* Copyright (C) 2010 Gilles Gigan (gilles.gigan@gmail.com)
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public  License as published by the
* Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE.
* See the GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#ifndef V4L2CTRL_H_
#define V4L2CTRL_H_

 //returns the number of controls (standard and private V4L2 controls only)
int count_v4l2_controls(struct video_device *);
//Populate the control_list with reported V4L2 controls
//and returns how many controls were created
int create_v4l2_controls(struct video_device *, struct control *, int);
//returns the value of a control
int get_control_value_v4l2(struct video_device *, struct control *, int *);
//sets the value of a control
int set_control_value_v4l2(struct video_device *, struct control *, int *);

#endif /*V4L2CTRL_H_*/
