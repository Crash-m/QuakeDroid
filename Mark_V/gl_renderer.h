// Baker

#ifndef __GL_RENDERER_H
#define __GL_RENDERER_H

#include "core_opengl.h"

///////////////////////////////////////////////////////////////////////////////
//  OPENGL: Renderer capabilities
///////////////////////////////////////////////////////////////////////////////

typedef struct
{
	const char	*gl_vendor;
	const char	*gl_renderer;
	const char	*gl_version;
	const char	*gl_extensions;
	char		*gl_extensions_nice;

	cbool		isIntelVideo;
	cbool		gl_mtexable;
	int			gl_max_texture_size;
	cbool		gl_texture_env_combine;
	cbool		gl_texture_env_add;
	cbool		gl_texture_non_power_of_two;
	cbool		gl_swap_control;
	cbool		gl_anisotropy_able;
	float		gl_max_anisotropy; //johnfitz
	int			gl_stencilbits; //johnfitz

	GLenum		TEXTURE0, TEXTURE1; //johnfitz

	PFNGLMULTITEXCOORD2FARBPROC			GL_MTexCoord2fFunc;		// glMultiTexCoord2
	PFNGLACTIVETEXTUREARBPROC			GL_SelectTextureFunc;	// glActiveTexture ?
	PFNGLCLIENTACTIVETEXTUREARBPROC		GL_ClientActiveTexture;	// glClientActiveTexture



//	glColorTableEXT
//		glColorTableEXT(GL_SHARED_TEXTURE_PALETTE_EXT, GL_RGB, 256, GL_RGB, GL_UNSIGNED_BYTE,
//		(void *) thePalette);
} renderer_t;

extern renderer_t renderer;

void GL_VID_SetMode_GL_Evaluate_Renderer (void);
void GL_VID_SetMode_GL_SetupState (void);

//#ifdef _WIN32
//#include <windows.h> // Why?  APIENTRY?
//#endif

#ifdef DIRECT3D8_WRAPPER // dx8 - The #include for the wrapper
	#include "dx8_mh_wrapper.h"
#endif // DIRECT3D8_WRAPPER
#ifdef DIRECT3D9_WRAPPER // dx9 - The #include for the wrapper
	#include "dx9_mh_wrapper.h"
#endif // DIRECT3D9_WRAPPER

// OpenGLES:   extern void GL_APIENTRY glDepthRangef (GLclampf zNear, GLclampf zFar);	// Float
// OpenGL 1.2: extern void (APIENTRY *eglDepthRange) (GLclampd zNear, GLclampd zFar);	// Double
// OpenGLES :   extern void GL_APIENTRY glFrustumf (GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);
// OpenGL 1,2:  extern void (APIENTRY *eglFrustum) (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
// GL_API void GL_APIENTRY glOrthof (GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);
// extern void (APIENTRY *eglOrtho) (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);

// Fun guys:  glDepthRangef, glOrthof, glFrustumf
#ifdef PLATFORM_OPENGLES
	extern void (APIENTRY *eglDepthRange) (GLclampf zNear, GLclampf zFar);	// Float
	extern void (APIENTRY *eglFrustum) (GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);
	extern void (APIENTRY *eglOrthoX) (GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);
#else
	extern void (APIENTRY *eglDepthRange) (GLclampd zNear, GLclampd zFar);	// Double
	extern void (APIENTRY *eglFrustum) (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
	extern void (APIENTRY *eglOrthoX) (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
#endif

extern void (APIENTRY *eglAlphaFunc) (GLenum func, GLclampf ref);
//extern void (APIENTRY *eglBegin) (GLenum mode);
extern void (APIENTRY *eglBindTexture) (GLenum target, GLuint texture);
extern void (APIENTRY *eglBlendFunc) (GLenum sfactor, GLenum dfactor);
extern void (APIENTRY *eglClear) (GLbitfield mask);
extern void (APIENTRY *eglClearColor) (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
extern void (APIENTRY *eglClearStencil) (GLint s);
//extern void (APIENTRY *eglColor3f) (GLfloat red, GLfloat green, GLfloat blue);

#define eglColor3f(red,green,blue) 	eglColor4f (red, green, blue, 1.0)
#define eglColor3fv(v) eglColor4f (v[0], v[1], v[2], 1.0)
//extern void (APIENTRY *eglColor3fv) (const GLfloat *v);
//extern void (APIENTRY *eglColor3ubv) (const GLubyte *v);
extern void (APIENTRY *eglColor4f) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define eglColor4fv(v) eglColor4f (v[0], v[1], v[2], v[3])
//extern void (APIENTRY *eglColor4fv) (const GLfloat *v);
//#define eglColor4ub(red, green,blue, alpha) eglColor4ub (red, green, blue, alpha/255.0);
extern void (APIENTRY *eglColor4ub) (GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);

#define eglColor4ubv(v) eglColor4ub (v[0], v[1], v[2], v[3])
//extern void (APIENTRY *eglColor4ubv) (const GLubyte *v);
extern void (APIENTRY *eglCopyTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern void (APIENTRY *eglColorMask) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
extern void (APIENTRY *eglCullFace) (GLenum mode);
extern void (APIENTRY *eglDeleteTextures) (GLsizei n, const GLuint *textures);
extern void (APIENTRY *eglDepthFunc) (GLenum func);
extern void (APIENTRY *eglDepthMask) (GLboolean flag);
extern void (APIENTRY *eglDisable) (GLenum cap);
//extern void (APIENTRY *eglDrawBuffer) (GLenum mode);
extern void (APIENTRY *eglEnable) (GLenum cap);
//extern void (APIENTRY *eglEnd) (void);
extern void (APIENTRY *eglFinish) (void);
extern void (APIENTRY *eglFogf) (GLenum pname, GLfloat param);
extern void (APIENTRY *eglFogfv) (GLenum pname, const GLfloat *params);
#define eglFogi(X,Y) eglFogf (X, Y)
//extern void (APIENTRY *eglFogi) (GLenum pname, GLint param);
//extern void (APIENTRY *eglFogiv) (GLenum pname, const GLint *params);
extern void (APIENTRY *eglFrontFace) (GLenum mode);
// For reference OPENGLES:
extern void (APIENTRY *eglGenTextures) (GLsizei n, GLuint *textures);
extern void (APIENTRY *eglGetFloatv) (GLenum pname, GLfloat *params);
extern void (APIENTRY *eglGetIntegerv) (GLenum pname, GLint *params);
const GLubyte *(APIENTRY *eglGetString) (GLenum name);
//extern void (APIENTRY *eglGetTexImage) (GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
extern void (APIENTRY *eglGetTexParameterfv) (GLenum target, GLenum pname, GLfloat *params);
extern void (APIENTRY *eglHint) (GLenum target, GLenum mode);
extern void (APIENTRY *eglLineWidth) (GLfloat width);
extern void (APIENTRY *eglLoadIdentity) (void);
extern void (APIENTRY *eglLoadMatrixf) (const GLfloat *m);
extern void (APIENTRY *eglMatrixMode) (GLenum mode);
extern void (APIENTRY *eglMultMatrixf) (const GLfloat *m);
//extern void (APIENTRY *eglNormal3f) (GLfloat nx, GLfloat ny, GLfloat nz);
extern void (APIENTRY *eglPixelStorei) (GLenum pname, GLint param);
//extern void (APIENTRY *eglPolygonMode) (GLenum face, GLenum mode);
extern void (APIENTRY *eglPolygonOffset) (GLfloat factor, GLfloat units);
extern void (APIENTRY *eglPopMatrix) (void);
extern void (APIENTRY *eglPushMatrix) (void);
//extern void (APIENTRY *eglReadBuffer) (GLenum mode);
extern void (APIENTRY *eglReadPixels) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
extern void (APIENTRY *eglRotatef) (GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *eglScalef) (GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *eglScissor) (GLint x, GLint y, GLsizei width, GLsizei height);
extern void (APIENTRY *eglSelectBuffer) (GLsizei size, GLuint *buffer);
extern void (APIENTRY *eglShadeModel) (GLenum mode);
extern void (APIENTRY *eglStencilFunc) (GLenum func, GLint ref, GLuint mask);
extern void (APIENTRY *eglStencilOp) (GLenum fail, GLenum zfail, GLenum zpass);
//extern void (APIENTRY *eglTexCoord2f) (GLfloat s, GLfloat t);
//extern void (APIENTRY *eglTexCoord2fv) (const GLfloat *v);
extern void (APIENTRY *eglTexEnvf) (GLenum target, GLenum pname, GLfloat param);
extern void (APIENTRY *eglTexEnvi) (GLenum target, GLenum pname, GLint param);
extern void (APIENTRY *eglTexImage2D) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
extern void (APIENTRY *eglTexParameterf) (GLenum target, GLenum pname, GLfloat param);
extern void (APIENTRY *eglTexParameteri) (GLenum target, GLenum pname, GLint param);
extern void (APIENTRY *eglTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
extern void (APIENTRY *eglTranslatef) (GLfloat x, GLfloat y, GLfloat z);
//extern void (APIENTRY *eglVertex2f) (GLfloat x, GLfloat y);
//extern void (APIENTRY *eglVertex2fv) (const GLfloat *v);
//extern void (APIENTRY *eglVertex3f) (GLfloat x, GLfloat y, GLfloat z);
//extern void (APIENTRY *eglVertex3fv) (const GLfloat *v);
extern void (APIENTRY *eglViewportX) (GLint x, GLint y, GLsizei width, GLsizei height);


void eglOrtho	 (double left, double right, double bottom, double top, double zNear, double zFar);
void eglViewport (GLint x, GLint y, GLsizei width, GLsizei height);


typedef struct {
	float		s;
	float		t;
	float		s2;	// For multitexture - 2nd TMU
	float		t2;	// For multitexture - 2nd TMU
    float		x;
	float		y;
	float		z;
	struct {
		byte red;
		byte green;
		byte blue;
		byte alpha;
	};
	byte c4[4];
	float		redf;
	float		greenf;
	float		bluef;
	float		alphaf;
} floatsamx_t;

#define MAX_UNSIGNED_SHORT_65536 65536 // Cannot go larger than this because OpenGL glDrawElements indices accepts unsigned byte or short.

extern floatsamx_t		_ray_base[256 * 1024]; // 262144
extern floatsamx_t		*ray;

extern unsigned short	_idx_base[MAX_UNSIGNED_SHORT_65536];
extern unsigned short	*idx;
extern int				_idx_num;
extern int				ray_begin_mode;
extern cbool			ray_is_mtex;
extern cbool			ray_is_color;
extern int				ray_count;

// Stride is gap from first to first.  So sizeof structure works as stride.





#if 1 // Vertex array
#define egl_Emit_Untextured_Quad_2D(x, y, x2, y2)														\
	{ /* Render the untextured quad */																	\
		const GLfloat verts2d[] = { x,  y, 																\
									x2, y, 																\
									x2, y2,																\
									x,  y2 }; /* Top --> Right -> Right Bottom Left clockwise? */		\
		/* top right bottom left */																		\
																										\
		glEnableClientState		(GL_VERTEX_ARRAY);														\
		glVertexPointer			(2, GL_FLOAT, /*stride*/ 0, verts2d);									\
		glDrawArrays			(GL_TRIANGLE_FAN, /*start*/0, /*verts*/ 4);								\
		glDisableClientState	(GL_VERTEX_ARRAY);														\
	}  /* End render the quad */   // Ender


#define egl_Emit_Textured_Quad_2D(s0, t0, s1, t1, x, y, x2, y2)											\
	{ /* Render the texture quad */																		\
		const GLfloat texco2d[]	= {	s0, t0, 															\
									s1, t0, 															\
									s1, t1, 															\
									s0, t1}; /* Top --> Right -> Right Bottom Left clockwise */			\
		const GLfloat verts2d[] = { x,  y, 																\
									x2, y, 																\
									x2, y2,																\
									x,  y2 }; /* Top --> Right -> Right Bottom Left clockwise? */		\
		/* top right bottom left */																		\
																										\
		glEnableClientState		(GL_TEXTURE_COORD_ARRAY);												\
		glEnableClientState		(GL_VERTEX_ARRAY);														\
		glVertexPointer			(2, GL_FLOAT, /*stride*/ 0, verts2d);									\
		glTexCoordPointer		(2, GL_FLOAT, /*stride*/ 0, texco2d);									\
		glDrawArrays			(GL_TRIANGLE_FAN, /*start*/ 0, /*verts*/ 4);							\
		glDisableClientState	(GL_VERTEX_ARRAY);														\
		glDisableClientState	(GL_TEXTURE_COORD_ARRAY);												\
	} /* End render the texture */   // Ender


#define egl_Emit_Untextured_Tri_2D(x, y, x2, y2, x3, y3)												\
	{ /* Render the untextured triangle */																\
		const GLfloat verts2d[] = { x, y, x2, y2, x3, y3 };												\
		glEnableClientState		(GL_VERTEX_ARRAY);														\
		glVertexPointer			(2, GL_FLOAT, 0, verts2d);												\
		glDrawArrays			(GL_TRIANGLE_FAN, 0, /*verts*/ 3);										\
		glDisableClientState	(GL_VERTEX_ARRAY);														\
	}  /* End render the triangle */   // Ender

#define egl_Array_Reset(unused)		ray = _ray_base, ray_count = 0, ray_is_mtex = false, ray_is_color = false // Ender
#define egl_Elements_Reset(unused)	egl_Array_Reset (unused);  idx = _idx_base; _idx_num = 0 // Ender

#define egl_Begin_Lines_3D_Array(BEGINMODE)										egl_Array_Reset(unused) // Ender
#define egl_Begin_Untextured_Solo_Quad_3D_Array(BEGINMODE)						egl_Array_Reset(unused) // Ender
#define egl_Begin_Textured_Solo_Quad_2D_Array(BEGINMODE)						egl_Array_Reset(unused) // Ender
#define egl_Begin_Textured_Solo_Quad_3D_Array(BEGINMODE)						egl_Array_Reset(unused) // Ender

//#define egl_Begin_Array(BEGINMODE /*like GL_TRIANGLE_FAN */)					egl_Array_Reset(unused) // Ender
#define egl_Begin_Textured_Triangle_Strip_2D_Array(BEGINMODE)					egl_Array_Reset(unused) // Ender
#define egl_Begin_RGBf_Triangle_Fan_3D_Array(BEGINMODE)							egl_Array_Reset(unused) // Ender
#define egl_Begin_Texco_Vertex_3D_Array(BEGINMODE)								egl_Array_Reset(unused) // Ender
#define egl_Begin_Untextured_Triangle_Fan_3D_Array(BEGINMODE)					egl_Array_Reset(unused) // Ender
#define egl_Begin_Textured_Polygon_3D_Array(BEGINMODE)							egl_Array_Reset(unused) // Ender
#define egl_Begin_MTextured_Polygon_3D_Array(BEGINMODE)							egl_Array_Reset(unused) // Ender
#define egl_Begin_Untextured_Polygon_3D_Array(BEGINMODE)						egl_Array_Reset(unused) // Ender
#define egl_Begin_Textured_RGBA_Triangles_3D_Array(BEGINMODE)					egl_Array_Reset(unused) // Ender

#define egl_Begin_Untextured_RGBA_Triangle_Fan_3D_Array(BEGINMODE)				egl_Array_Reset(unused) // Ender
#define egl_Begin_Untextured_Triangles_3D_Array(BEGINMODE)						egl_Array_Reset(unused) // Ender
#define egl_Begin_Textured_ColorYNf_TriangleX_3D_Array(BEGINMODE, mtex, is_color)egl_Array_Reset(unused); ray_begin_mode = BEGINMODE, ray_is_mtex = (mtex), ray_is_color = (is_color) // Ender

#define egl_Begin_Untextured_Quads_3D_Elements(BEGINMODE)						egl_Elements_Reset(unused) // Ender
#define egl_Begin_Textured_RGBA_Quads_3D_Elements(BEGINMODE)					egl_Elements_Reset(unused) // Ender





#define egl_Add_Texco_RGBAUB_VertexV_3D(_s, _t, _c, _v)									\
	ray->red = (_c)[0], ray->green = (_c)[1], ray->blue = (_c)[2], ray->alpha = (_c)[3],\
	/*intentional trailing comma above */												\
	egl_Add_Texco_Vertex_3D(_s, _t, (_v)[0], (_v)[1], (_v)[2]) // Ender

// Alias model uses this
#define egl_Add_Texco_RGBAvf_VertexV_3D(_s, _t, _cfloats, _v)							\
	ray->redf = (_cfloats)[0], ray->greenf = (_cfloats)[1], ray->bluef = (_cfloats)[2], ray->alphaf = (_cfloats)[3],	\
	/*intentional trailing comma above */												\
	egl_Add_Texco_Vertex_3D(_s, _t, (_v)[0], (_v)[1], (_v)[2]) // Ender

#define egl_Add_Texco_RGBAvf_Vertex_3D(_s, _t, _cfloats, _x, _y, _z)							\
	ray->redf = (_cfloats)[0], ray->greenf = (_cfloats)[1], ray->bluef = (_cfloats)[2], ray->alphaf = (_cfloats)[3],	\
	/*intentional trailing comma above */												\
	egl_Add_Texco_Vertex_3D(_s, _t, _x, _y, _z) // Ender

#define egl_Add_MTexco_RGBAvf_VertexV_3D(_s, _t, _s2, _t2, _cfloats, _v) \
	ray->redf = (_cfloats)[0], ray->greenf = (_cfloats)[1], ray->bluef = (_cfloats)[2], ray->alphaf = (_cfloats)[3],	\
	/*intentional trailing comma above */												\
	egl_Add_MTexco_Vertex_3D(_s, _t, _s2, _t2, (_v)[0], (_v)[1], (_v)[2]) // Ender

#define egl_Add_MTexco_RGBAvf_Vertex_3D(_s, _t, _s2, _t2, _cfloats, _x, _y, _z) \
	ray->redf = (_cfloats)[0], ray->greenf = (_cfloats)[1], ray->bluef = (_cfloats)[2], ray->alphaf = (_cfloats)[3],	\
	/*intentional trailing comma above */												\
	egl_Add_MTexco_Vertex_3D(_s, _t, _s2, _t2, _x, _y, _z) // Ender


#define egl_Add_Vertex_3D(_x, _y, _z)							ray->x = (_x), ray->y = (_y), ray->z = (_z); ray ++; ray_count ++ // Ender
#define egl_Add_VertexV_3D(_v)									egl_Add_Vertex_3D ((_v)[0], (_v)[1], (_v)[2]) // Ender
#define egl_Add_Texco_Vertex_2D(_s, _t, _x, _y)					ray->s = _s, ray->t = _t, ray->x = (_x), ray->y = (_y); ray ++; ray_count ++ // Ender
#define egl_Add_Texco_Vertex_3D(_s, _t, _x, _y, _z)				ray->s = _s, ray->t = _t, ray->x = (_x), ray->y = (_y), ray->z = (_z); ray ++; ray_count ++ // Ender

#define egl_Add_Texco_VertexV_3D(_s, _t, _v)					egl_Add_Texco_Vertex_3D(_s, _t, (_v)[0], (_v)[1], (_v)[2]) // Ender
#define egl_Add_MTexco_Vertex_3D(_s, _t, _s2, _t2, _x, _y, _z)  ray->s2 = _s2, ray->t2 = _t2, egl_Add_Texco_Vertex_3D(_s, _t, _x, _y, _z) // Ender
#define egl_Add_MTexco_VertexV_3D(_s, _t, _s2, _t2, _v)			ray->s2 = _s2, ray->t2 = _t2, egl_Add_Texco_Vertex_3D(_s, _t, (_v)[0], (_v)[1], (_v)[2]) // Ender

// Float colors
#define egl_End_Textured_ColorYNf_TriangleX_3D_Array()													\
	glEnableClientState		(GL_TEXTURE_COORD_ARRAY);													\
	glEnableClientState		(GL_VERTEX_ARRAY);															\
	if (ray_is_color) {																					\
		glEnableClientState	(GL_COLOR_ARRAY);															\
		glColorPointer		(4 /*rgba*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].redf);\
	}																									\
	glTexCoordPointer		(2 /*dimension*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].s); \
	if (ray_is_mtex) { /*switch to mtex and enable */													\
		renderer.GL_ClientActiveTexture (renderer.TEXTURE1);											\
		glEnableClientState		(GL_TEXTURE_COORD_ARRAY);												\
		glTexCoordPointer	(2, GL_FLOAT, sizeof(floatsamx_t), &_ray_base[0].s2);						\
	}																									\
	glVertexPointer			(3 /*dimension*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].x); \
	glDrawArrays			(ray_begin_mode, /*start*/ 0, /*vertex count*/ ray_count);					\
	if (ray_is_color)																					\
		glDisableClientState(GL_COLOR_ARRAY);															\
	if (ray_is_mtex) { /*switch to mtex and enable */													\
		glDisableClientState	(GL_TEXTURE_COORD_ARRAY);												\
		renderer.GL_ClientActiveTexture (renderer.TEXTURE0);											\
	}																									\
	glDisableClientState	(GL_TEXTURE_COORD_ARRAY);													\
	glDisableClientState	(GL_VERTEX_ARRAY) // Ender


#define egl_End_MTextured_Polygon_3D_Array()															\
	glEnableClientState		(GL_TEXTURE_COORD_ARRAY); GL_ErrorPrint;													\
	glEnableClientState		(GL_VERTEX_ARRAY);	GL_ErrorPrint;														\
	glTexCoordPointer		(2 /*dimension*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].s); GL_ErrorPrint;\
																										\
	renderer.GL_ClientActiveTexture (renderer.TEXTURE1);	GL_ErrorPrint;											\
	glEnableClientState		(GL_TEXTURE_COORD_ARRAY);GL_ErrorPrint;													\
	glTexCoordPointer		(2, GL_FLOAT, sizeof(floatsamx_t), &_ray_base[0].s2);	GL_ErrorPrint;					\
																										\
	glVertexPointer			(3 /*dimension*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].x);GL_ErrorPrint; \
	glDrawArrays			(GL_TRIANGLE_FAN, /*start*/ 0, /*vertex count*/ ray_count);			GL_ErrorPrint;			\
																										\
	glDisableClientState	(GL_TEXTURE_COORD_ARRAY);		GL_ErrorPrint;											\
	renderer.GL_ClientActiveTexture (renderer.TEXTURE0);	GL_ErrorPrint;											\
																										\
	glDisableClientState	(GL_TEXTURE_COORD_ARRAY);	GL_ErrorPrint;												\
	glDisableClientState	(GL_VERTEX_ARRAY); GL_ErrorPrint // Ender

#define egl_End_Textured_RGBA_Triangles_3D_Array()	 													\
	glEnableClientState		(GL_COLOR_ARRAY);															\
	glEnableClientState		(GL_TEXTURE_COORD_ARRAY);													\
	glEnableClientState		(GL_VERTEX_ARRAY);															\
	glColorPointer			(4 /*rgba*/, GL_UNSIGNED_BYTE, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].red);\
	glTexCoordPointer		(2 /*dimension*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].s); \
	glVertexPointer			(3 /*dimension*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].x); \
	glDrawArrays			(GL_TRIANGLES, /*start*/ 0, /*vertex count*/ ray_count); /*1 QUAD via FAN*/ \
	glDisableClientState	(GL_COLOR_ARRAY);															\
	glDisableClientState	(GL_TEXTURE_COORD_ARRAY);													\
	glDisableClientState	(GL_VERTEX_ARRAY) // Ender

#define egl_End_Textured_Solo_Quad_2D_Array() \
	glEnableClientState		(GL_TEXTURE_COORD_ARRAY);													\
	glEnableClientState		(GL_VERTEX_ARRAY);															\
	glTexCoordPointer		(2 /*dimension*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].s);\
	glVertexPointer			(2 /*dimension*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].x);\
	glDrawArrays			(GL_TRIANGLE_FAN, /*start*/ 0, /*vertex count*/ 4);							\
	glDisableClientState	(GL_TEXTURE_COORD_ARRAY);													\
	glDisableClientState	(GL_VERTEX_ARRAY) // Ender

#define egl_End_Textured_Solo_Quad_3D_Array()	 														\
	glEnableClientState		(GL_TEXTURE_COORD_ARRAY);													\
	glEnableClientState		(GL_VERTEX_ARRAY);															\
	glTexCoordPointer		(2 /*dimension*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].s); \
	glVertexPointer			(3 /*dimension*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].x); \
	glDrawArrays			(GL_TRIANGLE_FAN, /*start*/ 0, /*vertex count*/ 4); /*1 QUAD via FAN*/		\
	glDisableClientState	(GL_TEXTURE_COORD_ARRAY);													\
	glDisableClientState	(GL_VERTEX_ARRAY) // Ender
	

#define egl_End_Untextured_Polygon_3D_Array()															\
	glEnableClientState		(GL_VERTEX_ARRAY);															\
	glVertexPointer			(3 /*dimensions*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].x);\
	glDrawArrays			(GL_TRIANGLE_FAN, /*start*/ 0, /*vertex count*/ ray_count);						\
	glDisableClientState	(GL_VERTEX_ARRAY) // Ender

#define egl_End_Textured_Polygon_3D_Array()																\
	glEnableClientState		(GL_TEXTURE_COORD_ARRAY);GL_ErrorPrint;													\
	glEnableClientState		(GL_VERTEX_ARRAY);		GL_ErrorPrint;													\
	glTexCoordPointer		(2 /*texco*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].s);GL_ErrorPrint; \
	glVertexPointer			(3 /*dimensions*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].x);GL_ErrorPrint;\
	glDrawArrays			(GL_TRIANGLE_FAN,/*start*/ 0, /*vertex count*/ ray_count);	GL_ErrorPrint;					\
	glDisableClientState	(GL_TEXTURE_COORD_ARRAY);	GL_ErrorPrint;												\
	glDisableClientState	(GL_VERTEX_ARRAY) ;GL_ErrorPrint// Ender

#define egl_End_Textured_Triangle_Strip_2D_Array()														\
	glEnableClientState		(GL_TEXTURE_COORD_ARRAY);													\
	glEnableClientState		(GL_VERTEX_ARRAY);															\
	glTexCoordPointer		(2 /*texco*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].s); \
	glVertexPointer			(2 /*dimensions*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].x);\
	glDrawArrays			(GL_TRIANGLE_STRIP, /*start*/ 0, /*vertex count*/ ray_count);				\
	glDisableClientState	(GL_VERTEX_ARRAY);															\
	glDisableClientState	(GL_TEXTURE_COORD_ARRAY) // Ender

#define egl_Add_Untextured_QuadV_3D_Element(_v0, _v1, _v2, _v3)											\
	egl_Add_VertexV_3D (_v0);																			\
	egl_Add_VertexV_3D (_v1);																			\
	egl_Add_VertexV_3D (_v2);																			\
	egl_Add_VertexV_3D (_v3);																			\
	egl_Complete_This_Untextured_Quad_3D_Element () // Ender

#define egl_Add_Untextured_Quad_Vert_3D_Element(_x, _y, _z)		egl_Add_Vertex_3D (_x, _y, _z) // Ender

#define egl_Complete_This_Untextured_Quad_3D_Element()													\
/* emit 2 triangles 0 1 2 and 2 3 0 */																	\
	*idx++ = _idx_num + 0;	*idx++ = _idx_num + 1; *idx++ = _idx_num + 2;								\
	*idx++ = _idx_num + 2;	*idx++ = _idx_num + 3; *idx++ = _idx_num + 0;								\
	_idx_num += 4 // Ender

#define egl_Complete_Textured_Quad_3D_Element()															\
/* emit 2 triangles 0 1 2 and 2 3 0 */																	\
	*idx++ = _idx_num + 0;	*idx++ = _idx_num + 1; *idx++ = _idx_num + 2;								\
	*idx++ = _idx_num + 2;	*idx++ = _idx_num + 3; *idx++ = _idx_num + 0;								\
	_idx_num += 4 // Ender


#define egl_Complete_This_Textured_RGBA_Quad_3D_Element egl_Complete_This_Untextured_Quad_3D_Element // Ender

#define egl_End_Untextured_Quads_3D_Elements()	/* Elements! */											\
	glEnableClientState		(GL_VERTEX_ARRAY);															\
	glVertexPointer			(3 /*dimension*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].x); \
	glDrawElements			(GL_TRIANGLES, /* count of indices, not triangles */ (_idx_num / 4) * 6, GL_UNSIGNED_SHORT, _idx_base); \
	glDisableClientState	(GL_VERTEX_ARRAY) // Ender

//#define egl_End_Textured_Quads_3D_Elements()	/* Elements! */											\
//	glEnableClientState		(GL_TEXTURE_COORD_ARRAY);													\
//	glEnableClientState		(GL_VERTEX_ARRAY);															\
//	glColorPointer			(4 /*rgba*/, GL_UNSIGNED_BYTE, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].red);	\
//	glTexCoordPointer		(2 /*texco*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].s); \
//	glVertexPointer			(3 /*dimension*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].x); \
//	glDrawElements			(GL_TRIANGLES, /* count of indices, not triangles */ (_idx_num / 4) * 6, GL_UNSIGNED_SHORT, _idx_base); \
//	glDisableClientState	(GL_TEXTURE_COORD_ARRAY);													\
//	glDisableClientState	(GL_VERTEX_ARRAY) // Ender

#define egl_End_Textured_RGBA_Quads_3D_Elements()	/* Elements! */										\
	glEnableClientState		(GL_COLOR_ARRAY);															\
	glEnableClientState		(GL_TEXTURE_COORD_ARRAY);													\
	glEnableClientState		(GL_VERTEX_ARRAY);															\
	glColorPointer			(4 /*rgba*/, GL_UNSIGNED_BYTE, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].red);	\
	glTexCoordPointer		(2 /*texco*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].s); \
	glVertexPointer			(3 /*dimension*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].x); \
	glDrawElements			(GL_TRIANGLES, /* count of indices, not triangles */ (_idx_num / 4) * 6, GL_UNSIGNED_SHORT, _idx_base); \
	glDisableClientState	(GL_COLOR_ARRAY);															\
	glDisableClientState	(GL_TEXTURE_COORD_ARRAY);													\
	glDisableClientState	(GL_VERTEX_ARRAY) // Ender

#define egl_End_Untextured_Solo_Quad_3D_Array()	/*Array*/												\
	glEnableClientState		(GL_VERTEX_ARRAY);															\
	glVertexPointer			(3 /*dimension*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].x);\
	glDrawArrays			(GL_TRIANGLE_FAN, /*start*/ 0, /*vertex count*/ 4 /*QUAD*/);				\
	glDisableClientState	(GL_VERTEX_ARRAY) // Ender

#define egl_End_Untextured_Triangles_3D_Array()	/*Array*/												\
	glEnableClientState		(GL_VERTEX_ARRAY);															\
	glVertexPointer			(3 /*dimension*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].x);\
	glDrawArrays			(GL_TRIANGLES, /*start*/ 0, /*vertex count*/ ray_count);					\
	glDisableClientState	(GL_VERTEX_ARRAY) // Ender


#define egl_End_Untextured_Triangle_Fan_3D_Array()	/*Array*/											\
	glEnableClientState		(GL_VERTEX_ARRAY);															\
	glVertexPointer			(3 /*dimension*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].x);\
	glDrawArrays			(GL_TRIANGLE_FAN, /*start*/ 0, /*vertex count*/ ray_count);					\
	glDisableClientState	(GL_VERTEX_ARRAY) // Ender

#define egl_End_Untextured_RGBA_Triangle_Fan_3D_Array()	/*Array*/										\
	glEnableClientState		(GL_COLOR_ARRAY);															\
	glEnableClientState		(GL_VERTEX_ARRAY);															\
	glColorPointer			(4 /*rgba*/, GL_UNSIGNED_BYTE, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].red); \
	glVertexPointer			(3 /*dimension*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].x);\
	glDrawArrays			(GL_TRIANGLE_FAN, /*start*/ 0, /*vertex count*/ ray_count);					\
	glDisableClientState	(GL_COLOR_ARRAY);															\
	glDisableClientState	(GL_VERTEX_ARRAY) // Ender

// Float colors
#define egl_Add_RGBf_VertexV_3D_Array(_red, _green, _blue, V)											\
	ray->x = (V)[0], ray->y = (V)[1], ray->z = (V)[2], /* ... */										\
		ray->redf = _red, ray->greenf = _green, ray->bluef = _blue, ray->alphaf = 1.0; ray ++; ray_count ++ // Ender

#define egl_Add_RGBAUB_VertexV_3D_Array(_red, _green, _blue, _alpha, V)									\
	ray->x = (V)[0], ray->y = (V)[1], ray->z = (V)[2], /* ... */										\
		ray->red = _red, ray->green = _green, ray->blue = _blue, ray->alpha = _alpha; ray ++; ray_count ++ // Ender

#define egl_Add_RGBAUBV_VertexV_3D_Array(_color, V) \
	egl_Add_RGBAUB_VertexV_3D_Array ((_color)[0], (_color)[1], (_color)[2], (_color)[3], V) // Ender



// Float colors
#define egl_End_RGBf_Triangle_Fan_3D_Array()															\
	glEnableClientState		(GL_VERTEX_ARRAY);															\
	glEnableClientState		(GL_COLOR_ARRAY);															\
	glColorPointer			(4 /*rgba*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].red);	\
	glVertexPointer			(3 /*dimensions*/, GL_FLOAT, sizeof(floatsamx_t), &_ray_base[0].x);			\
	glDrawArrays			(GL_TRIANGLE_FAN, /*start*/ 0, /*vertex count*/ ray_count);					\
	glDisableClientState	(GL_COLOR_ARRAY);															\
	glDisableClientState	(GL_VERTEX_ARRAY) // Ender

#define egl_End_Lines_3D_Array()																		\
	if (ray_count) {																					\
		glEnableClientState		(GL_VERTEX_ARRAY);														\
		glVertexPointer			(3 /*dimensions*/, GL_FLOAT, /*stride*/ sizeof(floatsamx_t), &_ray_base[0].x);\
		glDrawArrays			(GL_LINES, /*start*/ 0, /*vertex count*/ ray_count);					\
		glDisableClientState	(GL_VERTEX_ARRAY);														\
	} // Ender


#else

// Crusty style ....


	

#define egl_Emit_Untextured_Quad_2D (x, y, x2, y2)														\
	eglBegin (GL_QUADS); /* h file */																	\
	eglVertex2f (x,  y );																				\
	eglVertex2f (x2, y );																				\
	eglVertex2f (x2, y2);																				\
	eglVertex2f (x,  y2);																				\
	eglEnd () // Ender

#define egl_Emit_Textured_Quad_2D(s0, t0, s1, t1, x, y, x2, y2)											\
	eglBegin (GL_QUADS); /* h file */																	\
	eglTexCoord2f (s0, t0);																				\
	eglVertex2f (x0, y0);																				\
	eglTexCoord2f (s1, t0);																				\
	eglVertex2f (x1, y0);																				\
	eglTexCoord2f (s1, t1);																				\
	eglVertex2f (x1, y1);																				\
	eglTexCoord2f (s0, t1);																				\
	eglVertex2f (x0, y1);																				\
	eglEnd () // Ender


#define egl_Emit_Untextured_Tri_2D (x, y, x2, y2, x3, y3)												\
	eglBegin (GL_TRIANGLE_FAN); /* h file */															\
	eglVertex2f (x,  y  );																				\
	eglVertex2f (x2, y2 );																				\
	eglVertex2f (x3, y3 );																				\
	eglEnd () // Ender

#endif // End non-vertex array

#ifdef _WIN32

// I think I commented this out because it is flat out wrong.
// We were creating variables here :(  In every file, no less!
// Or were we?  Anyway you need an extern on them if you want to do this still.

//LONG (WINAPI *eChangeDisplaySettings) (LPDEVMODE lpDevMode, DWORD dwflags);
//
//HGLRC (WINAPI *ewglCreateContext) (HDC);
//BOOL  (WINAPI *ewglDeleteContext) (HGLRC);
//HGLRC (WINAPI *ewglGetCurrentContext) (VOID);
//HDC   (WINAPI *ewglGetCurrentDC) (VOID);
//PROC  (WINAPI *ewglGetProcAddress)(LPCSTR);
//BOOL  (WINAPI *ewglMakeCurrent) (HDC, HGLRC);
//BOOL  (WINAPI *eSetPixelFormat) (HDC, int, CONST PIXELFORMATDESCRIPTOR *);

#define eSystem_GL_GetProcAddress ewglGetProcAddress

#endif // _WIN32

#ifndef _WIN32
#define eSystem_GL_GetProcAddress System_GL_GetProcAddress
#endif // ! WIN32

#endif //  ! __GL_RENDERER_H


