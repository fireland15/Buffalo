#pragma once

#include <string>
#include <Meatball/Rendering/AttributeDataType.hpp>

namespace Meatball {
    namespace Rendering {
        struct AttributeVariable {
            const AttributeDataType Type;
            const GLint Location;
            const std::string Name;
            const GLint Size;

            AttributeVariable() : Type(AttributeDataType::Float), Location(0), Name(std::string("")), Size(0) {};
            AttributeVariable(AttributeDataType type, GLint location, const std::string& name, GLint size);
        };
    }
}