#version 330 core

// Wyj�cie kolor�w w formacie RGBA
out vec4 FragColor;

// Importuje kolor z Vertex Shadera
in vec3 color;
// Importuje wsp�rz�dne tekstury z Vertex Shadera
in vec2 texCoord;
// Importuje normaln� z Vertex Shadera
in vec3 Normal;
// Importuje bie��c� pozycj� z Vertex Shadera
in vec3 crntPos;

// Pobiera jednostk� tekstury z funkcji g��wnej
uniform sampler2D tex0;
// Pobiera kolor �wiat�a z funkcji g��wnej
uniform vec4 lightColor;
// Pobiera pozycj� �wiat�a z funkcji g��wnej
uniform vec3 lightPos;
// Pobiera pozycj� kamery z funkcji g��wnej
uniform vec3 camPos;

// Flaga okre�laj�ca, czy u�ywa� tekstury
uniform int useTexture;

void main()
{
    // O�wietlenie otoczenia
    float ambient = 0.20f;

    // O�wietlenie dyfuzyjne
    vec3 normal = normalize(Normal);
    vec3 lightDirection = normalize(lightPos - crntPos);
    float diffuse = max(dot(normal, lightDirection), 0.0f);

    // O�wietlenie lustrzane
    float specularLight = 0.50f;
    vec3 viewDirection = normalize(camPos - crntPos);
    vec3 reflectionDirection = reflect(-lightDirection, normal);
    float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 8);
    float specular = specAmount * specularLight;

    // Obliczenie ko�cowego koloru piksela
    FragColor = (useTexture == 1 ? texture(tex0, texCoord) : vec4(color, 1.0)) * lightColor * (diffuse + ambient + specular);
}
