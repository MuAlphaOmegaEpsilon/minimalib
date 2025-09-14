#pragma once
#include <X11/Xlib.h>
#include "str.hpp"

str_t x_event_name(int x_event_type)
{	switch(x_event_type)
	{
		case ClientMessage:    return str("ClientMessage");
		case KeyPress:         return str("KeyPress");
		case KeyRelease:       return str("KeyRelease");
		case ButtonPress:      return str("ButtonPress");
		case ButtonRelease:    return str("ButtonRelease");
		case MotionNotify:     return str("MotionNotify");
		case EnterNotify:      return str("EnterNotify");
		case LeaveNotify:      return str("LeaveNotify");
		case FocusIn:          return str("FocusIn");
		case FocusOut:         return str("FocusOut");
		case KeymapNotify:     return str("KeymapNotify");
		case Expose:           return str("Expose");
		case GraphicsExpose:   return str("GraphicsExpose");
		case NoExpose:         return str("NoExpose");
		case VisibilityNotify: return str("VisibilityNotify");
		case CreateNotify:     return str("CreateNotify");
		case DestroyNotify:    return str("DestroyNotify");
		case UnmapNotify:      return str("UnmapNotify");
		case MapNotify:        return str("MapNotify");
		case MapRequest:       return str("MapRequest");
		case ReparentNotify:   return str("ReparentNotify");
		case ConfigureNotify:  return str("ConfigureNotify");
		case ConfigureRequest: return str("ConfigureRequest");
		case GravityNotify:    return str("GravityNotify");
		case ResizeRequest:    return str("ResizeRequest");
		case CirculateNotify:  return str("CirculateNotify");
		case CirculateRequest: return str("CirculateRequest");
		case PropertyNotify:   return str("PropertyNotify");
		case SelectionClear:   return str("SelectionClear");
		case SelectionRequest: return str("SelectionRequest");
		case SelectionNotify:  return str("SelectionNotify");
		case ColormapNotify:   return str("ColormapNotify");
		case MappingNotify:    return str("MappingNotify");
		case GenericEvent:     return str("GenericEvent");
		default:               return str("UNKNOWN");
	}
}

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
