#version 330 core

// Wyjœcie kolorów w formacie RGBA
out vec4 FragColor;

// Importuje kolor z Vertex Shadera
in vec3 color;
// Importuje wspó³rzêdne tekstury z Vertex Shadera
in vec2 texCoord;
// Importuje normaln¹ z Vertex Shadera
in vec3 Normal;
// Importuje bie¿¹c¹ pozycjê z Vertex Shadera
in vec3 crntPos;

// Pobiera jednostkê tekstury z funkcji g³ównej
uniform sampler2D tex0;
// Pobiera kolor œwiat³a z funkcji g³ównej
uniform vec4 lightColor;
// Pobiera pozycjê œwiat³a z funkcji g³ównej
uniform vec3 lightPos;
// Pobiera pozycjê kamery z funkcji g³ównej
uniform vec3 camPos;

// Flaga okreœlaj¹ca, czy u¿ywaæ tekstury
uniform int useTexture;

void main()
{
    // Oœwietlenie otoczenia
    float ambient = 0.20f;

    // Oœwietlenie dyfuzyjne
    vec3 normal = normalize(Normal);
    vec3 lightDirection = normalize(lightPos - crntPos);
    float diffuse = max(dot(normal, lightDirection), 0.0f);

    // Oœwietlenie lustrzane
    float specularLight = 0.50f;
    vec3 viewDirection = normalize(camPos - crntPos);
    vec3 reflectionDirection = reflect(-lightDirection, normal);
    float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 8);
    float specular = specAmount * specularLight;

    // Obliczenie koñcowego koloru piksela
    FragColor = (useTexture == 1 ? texture(tex0, texCoord) : vec4(color, 1.0)) * lightColor * (diffuse + ambient + specular);
}
