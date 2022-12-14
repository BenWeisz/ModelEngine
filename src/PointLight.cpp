#include "PointLight.h"

PointLight::PointLight(ShaderProgram* const shader, glm::vec3 color, const std::string& name) : Light(color, LIGHT_POINT, name) {
    m_Shader = shader;
    m_Model = ModelLoader::NormalsCube();

    m_Transform.SetScale(0.8f, 0.8f, 0.8f);
    m_Transform.SetTranslation(0.0f, 4.0f, -5.0f);

    m_Time = 0.0f;
}

void PointLight::Draw(const float deltaTime) const {
    assert(m_Model != nullptr);
    m_Shader->SetUniform3fv("u_FlatColor", &m_Color[0]);

    m_Model->Bind();
    m_Model->Draw();
    m_Model->Unbind();
}

void PointLight::Update(const float deltaTime) {
    m_Time += deltaTime;
    m_Transform.SetTranslation(5.0f * cos(m_Time / 2.0f), 4.0f, 5.0f * sin(m_Time / 2.0f));
    m_Transform.SetRotation(45.0f * cos(m_Time / 2.0f), 45.0f * sin(m_Time / 2.0f), 45.0f * sin(m_Time / 2.0f));
}

ShaderProgram* PointLight::GetShader() const {
    return m_Shader;
}

Transform PointLight::GetTransform() const {
    return m_Transform;
}
