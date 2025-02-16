#pragma once

#include <qopenglcontext.h>
#include <qopenglfunctions.h>
#include <qopenglextrafunctions.h>

//链接
#define OPENGL_FUNCTIONS QOpenGLContext::currentContext()->functions()
//链接着上下文 VAO VBO
#define OPENGL_EXTRA_FUNCTIONS QOpenGLContext::currentContext()->extraFunctions()