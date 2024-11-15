#pragma once
#include <string>
#include <unordered_map>

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader
{
private: 
	//Declarations
	std::string m_filePath;
	unsigned int m_rendererID;
	std::unordered_map<std::string, int> m_uniformLocationCache;
public:
	Shader(const std::string& filepath);
	~Shader();

	//Binding and Unbinding
	void bind() const;
	void unBind() const;

	//Set Uniforms
	void setUniform1i(const std::string& name, float value);
	void setUniform1f(const std::string& name, float value);
	void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
private:
	ShaderProgramSource parseShader(const std::string& filepath);
	unsigned int compileShader(unsigned int type, const std::string& source);
	unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);
    int getUniformLocation(const std::string& name);
};