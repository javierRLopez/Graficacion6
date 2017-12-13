#include "Object3D.h"



void Object3D::setup(std::vector<GLfloat> vertex, std::vector<GLint> * index)
{


	transformID = glGetUniformLocation(shader, "transform");
	colorID = glGetUniformLocation(shader, "vColor");
	numVertex = vertex.size() / 4;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, vertex.size() * sizeof(GLfloat), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0/*offset*/, vertex.size() * sizeof(GLfloat), &vertex.at(0));
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(0);
}
void Object3D::draw(glm::mat4 transform, glm::vec4 color)
{
	glUseProgram(shader);
	glUniformMatrix4fv(transformID, 1, GL_FALSE, glm::value_ptr(transform));
	glUniform4fv(colorID, 1, glm::value_ptr(color));

	//activamos el vertex array object y dibujamos
	glBindVertexArray(vao);
	//glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glEnableVertexAttribArray(0);

	glDrawArrays(GL_TRIANGLES, 0, numVertex);

}
void Object3D::Shaders(std::string vS, std::string fS)
{
	std::string strVertexShader = loadTextFile(vS);
	std::string strFragmentShader = loadTextFile(fS);
	InitializeProgram(shader, strVertexShader, strFragmentShader);
}