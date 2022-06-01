
#include "VBO.h"

VBO::VBO(GLfloat* vertices, GLsizeiptr size_VBO)
{
	// generate Vertexbuffer 
	glGenBuffers(1, &Profile_VBO);

	// Binds the name buffer to object buffer , helps in rendering,
	// specifying the type of VBO (GL_ARRAY_BUFFER)
	glBindBuffer(GL_ARRAY_BUFFER, Profile_VBO);

	// storing vertices in buffer 
	// GL_STATIC_DRAW : verices will be modified once and used many times and draw an img on screen
	glBufferData(GL_ARRAY_BUFFER, size_VBO, vertices, GL_STATIC_DRAW);
}

void VBO::bind_VBO() { glBindBuffer(GL_ARRAY_BUFFER, Profile_VBO); }

void VBO::unbind_VBO() { glBindBuffer(GL_ARRAY_BUFFER, 0); }

void VBO::Delete_VBO() { glDeleteBuffers(1, &Profile_VBO); }
