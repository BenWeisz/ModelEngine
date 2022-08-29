#include "Light.h"

Light::Light(ShaderProgram* const shader, glm::vec3 color) {
    m_Shader = shader;
    m_Color = color;
    m_AmbientStrength = 0.1f;
    m_SpecularStrength = 0.5f;
}

ShaderProgram* Light::GetShader() const {
    return m_Shader;
}

glm::vec3 Light::GetColor() const {
    return m_Color;
}

float Light::GetAmbientStrength() const {
    return m_AmbientStrength;
}

float Light::GetSpecularStrength() const {
    return m_SpecularStrength;
}

void Light::SetColor(const float* rgb) {
    m_Color = glm::make_vec3(rgb);
}