/*  Copyright (C) 1996-1997  Id Software, Inc.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

    See file, 'COPYING', for details.
*/

#ifndef __MATHLIB__
#define __MATHLIB__

// mathlib.h

#include <math.h>

#if defined(QUAKE_GAME) || defined(DOUBLEVEC_T)
typedef double vec_t;
#else
typedef float vec_t;
#endif
typedef vec_t vec3_t[3];

#define	SIDE_FRONT		0
#define	SIDE_ON			2
#define	SIDE_BACK		1
#define	SIDE_CROSS		-2

#define	Q_PI	3.14159265358979323846

extern vec3_t tx_vec3_origin;

#define	EQUAL_EPSILON	0.001

qboolean tx_VectorCompare (vec3_t v1, vec3_t v2);

#define DotProduct(x,y) (x[0]*y[0]+x[1]*y[1]+x[2]*y[2])
#define VectorSubtract(a,b,c) {c[0]=a[0]-b[0];c[1]=a[1]-b[1];c[2]=a[2]-b[2];}
#define VectorAdd(a,b,c) {c[0]=a[0]+b[0];c[1]=a[1]+b[1];c[2]=a[2]+b[2];}
#define VectorCopy(a,b) {b[0]=a[0];b[1]=a[1];b[2]=a[2];}
#if 1 // Rotating brush support
#define VectorNegate(a,b) ((b)[0]=-(a)[0],(b)[1]=-(a)[1],(b)[2]=-(a)[2])
#endif

vec_t tx_Q_rint (vec_t in);
vec_t tx_DotProduct (vec3_t v1, vec3_t v2);
void tx_VectorSubtract (vec3_t va, vec3_t vb, vec3_t out);
void tx_VectorAdd (vec3_t va, vec3_t vb, vec3_t out);
void tx_VectorCopy (vec3_t in, vec3_t out);

double tx_VectorLength(vec3_t v);

void tx_VectorMA (vec3_t va, double scale, vec3_t vb, vec3_t vc);

void tx_CrossProduct (vec3_t v1, vec3_t v2, vec3_t cross);
vec_t tx_VectorNormalize (vec3_t v);
void tx_VectorInverse (vec3_t v);
void tx_VectorScale (vec3_t v, vec_t scale, vec3_t out);
#if 1 // Rotating brush support
vec_t tx_RadiusFromBounds (vec3_t mins, vec3_t maxs);
#endif

#endif
