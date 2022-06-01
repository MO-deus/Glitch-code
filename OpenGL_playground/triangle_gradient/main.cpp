
/*									-- All for the greater good --
* 
	Project : Understanding Graphics using OpenGL
	Author : Kush Waikar
	Date : 12-02-2022

	Notes : 1. All openGL objects are accessed using references.
*/

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>

#include "ShaderClass.h"
#include "VBO.h"
#include "EBO.h"
#include "VAO.h"

//class C_Shader_snippets{
//
//public:
//	const char* VertexShaderSource = "#version 330 core\n"
//		"layout (location = 0) in vec3 aPos;\n"
//		"void main()\n"
//		"{\n"
//		"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//		"}\0";
//	const char* FragmentShaderSource = "#version 330 core\n"
//		"out vec4 FragColor;\n"
//		"void main()\n"
//		"{\n"
//		"	FragColor = vec4(0.8f, 0.3f, 0.2f, 1.0f);\n"
//		"}\0";
//};
//
//  typedef class C_Shader_snippets Shader_snippets;

	int main()
	{
	//Shader_snippets shadder_instance; 

	// used to initialize the glfw library
	glfwInit();

	// 3 means 3.3 version and major/minor version of opengl
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// 2 profiles : 1.old 2.modern(core)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// defining the vertices 
	// verices of an eq triangle
	GLfloat vertices[] = {
		//				co-ordinates                alpha        colors
		-0.5f,     -0.5f *float(sqrt(3))/3,         0.0f,	0.8f, 0.3f,  0.02f,		// left bottom	0.
		 0.5f,	   -0.5f * float(sqrt(3)) / 3,      0.0f,	0.8f, 0.3f,  0.2f,		// right bottom	1.
		 0.0f,      0.5f * float(sqrt(3)) * 2/3,    0.0f,	1.0f, 0.6f,  0.32f,		// upper		2.
		-0.5f / 2,  0.5f * float(sqrt(3)) / 6,      0.0f,	0.9f, 0.45f, 0.17f,		// mid left		3.
		 0.5f / 2,  0.5f * float(sqrt(3)) / 6,      0.0f,	0.9f, 0.45f, 0.17f,		// mid right	4.
		 0.0f,     -0.5f * float(sqrt(3)) / 3,      0.0f,	0.8f, 0.3f,  0.02f		// mid bottom	5.
	};

	GLuint indices[] = 
	{
		0,5,3,
		5,1,4,
		3,4,2
	};

	GLFWwindow* window = glfwCreateWindow(800, 800, "Cpp_graphics", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// telling the program that the window will be used
	glfwMakeContextCurrent(window);

	//Actual graphics code ----------------------------------------------------------------------------------
	//load the GLAD library
	gladLoadGL();

	// render window from where to where
	// initial x and y to final x and y
	// z axis is ignored since 3d graphics are not generated
	glViewport(0, 0, 800, 800);

	// creating a value aka reference to store shader 
	// creating the vertex shader
	Shader ShaderProgram("Default.vert", "Default.frag");

	// storing data -----------------------------------------------------------------------------------------

	// Buffer for loading the verices data 
	// VBO [ Visual Buffer Object  ] stores the data of verices
	// VAO [ Visual Array Object   ] contains references to various VBOs
	// EBO [ Element Buffer Object ] stores the indices for verices
	//GLuint  VAO, VBO, EBO;

	// returns vertex array object(s)
	//glGenVertexArrays(1, &VAO);
	VAO m_vao;
	m_vao.bind_VAO();

	VBO m_vbo(vertices,	sizeof(vertices));
	EBO m_ebo(indices,	sizeof(indices));

	// links attributes such as coordinates and color to VAO
	m_vao.LinkAttrib(m_vbo, 0, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)0);
	m_vao.LinkAttrib(m_vbo, 1, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
	m_vao.unbind_VAO();
	m_vbo.unbind_VBO();
	m_ebo.unbind_EBO();

	// referencing uniform "scale_multiplier"
	// only be initialised after the shader program is active
	GLuint uniID = glGetUniformLocation(ShaderProgram.Profile_ShaderCLass, "scale_multiplier");

	// generate Vertexbuffer 
	//glGenBuffers(1, &VBO);

	//// generate ElementBuffer
	//glGenBuffers(1, &EBO);

	//// binds the VAO with name "array" 
	//glBindVertexArray(VAO);

	//// Binds the name buffer to object buffer , helps in rendering, specifying the type of VBO (GL_ARRAY_BUFFER)
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//// storing vertices in buffer 
	//// GL_STATIC_DRAW : verices will be modified once and used many times and draw an img on screen
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//// generating and binding the data of indices to EBO
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//// normalizes the data to floating point 
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	//// Enables the generic VertexArrayAttrib pointed by index 
	//glEnableVertexAttribArray(0);

	//// stoping [unbinding] the buffers
	//// order matters
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


	// Buffers : front and back buffer
	// front buffer : rendered items are displayed
	// back buffer : rendering is done 
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

	// clears the color buffer and executes the above command on color buffer
	glClear(GL_COLOR_BUFFER_BIT);

	/* front buffer has the default rendered window 
	*  in order to load the back buffer it should be swapped with
	* the front buffer
	*/
	glfwSwapBuffers(window);

	// main loop 
	// to keep the window running
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		// glUseProgram(ShaderProgram);	
		ShaderProgram.Shader_Inst_Activate();
		// uniform var is called
		glUniform1f(uniID, 0.5f);
		/*glBindVertexArray(VAO);*/
		m_vao.bind_VAO();
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, 9 , GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// deleting the Buffers
	/*glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);*/

	m_vao.Delete_VAO();
	m_vbo.Delete_VBO();
	m_ebo.Delete_EBO();
	ShaderProgram.Shader_Inst_Delete();

	// destroys the window
	glfwDestroyWindow(window);

	// terminates the library
	glfwTerminate();
	return 0;
}	