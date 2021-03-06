/*
* Copyright (C) 2007-2008 Gilles Gigan (gilles.gigan@gmail.com)
* eResearch Centre, James Cook University (eresearch.jcu.edu.au)
*
* This program was developed as part of the ARCHER project
* (Australian Research Enabling Environment) funded by a
* Systemic Infrastructure Initiative (SII) grant and supported by the Australian
* Department of Innovation, Industry, Science and Research
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

#ifndef H_FPS_PARAM_PROBE
#define H_FPS_PARAM_PROBE

#include "libvideo.h"

//index of the fps-param probe in the struct v4l_driver_probe known_driver_probes[] in v4l-control.c
#define FPS_PARAM_PROBE_INDEX	3
int fps_param_probe(struct video_device *, void **);
int fps_param_list_ctrl(struct video_device *, struct control *, void *);
int fps_param_get_ctrl(struct video_device *,  struct v4l2_queryctrl *, void *, int *);
int fps_param_set_ctrl(struct video_device *, struct v4l2_queryctrl *, int *, void *);

#endif /*H_FPS_PARAM_PROBE*/
