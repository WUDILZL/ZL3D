#pragma once

#include <qopenglcontext.h>
#include <qopenglfunctions.h>
#include <qopenglextrafunctions.h>

//����
#define OPENGL_FUNCTIONS QOpenGLContext::currentContext()->functions()
//������������ VAO VBO
#define OPENGL_EXTRA_FUNCTIONS QOpenGLContext::currentContext()->extraFunctions()