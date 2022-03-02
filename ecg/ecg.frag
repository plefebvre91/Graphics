#define THICKNESS 0.01

void analogic_screen_filter(inout vec3 color, in vec2 frag) {
    color *= sin(1200.0*frag.y);
}

vec2 clip(in vec2 value, in float minimum, in float maximum) {
   vec2 result = value;

   result.y *= smoothstep(minimum,0.5, value.x);
   result.y *= 1.0 - smoothstep(0.5,maximum, value.x);

   return result;
}


// https://www.shadertoy.com/view/XsyGRw

void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    // Curve color
    const vec3 blue = vec3(0.0,0.3,0.9);

    // Background color
    const vec3 black = vec3(0.05,0.05,0.05);

    // Frament coordinates [0,1]
    vec2 uv = fragCoord/iResolution.xy;

    // Final fragment color
    vec3 color = vec3(0.0, 0.0, 0.0);

    // Curve parameters
    const float frequence = 60.0;
    float phase = -3.0*iTime;

    // Signal function
    vec2 signal = vec2(0.0, 0.0);
    signal.x = uv.x;

    // 2 sinusoids
    signal.y = -(0.07*(sin(frequence*signal.x+phase))) + abs(0.4*(sin(frequence/5.0*signal.x+phase)));

    // Keep only the middle of the function
    signal = clip(signal, 0.42, 0.6);

    // Display vertically-centered
    signal.y += 0.5;

    // Intensity decreases at the borders
    vec2 intensity = vec2(uv.x, max(1.0/abs(0.5-uv.x), 1.0));
    intensity = clip(intensity, 0.01, 0.99);

    // Fragment value is the distance between the fragment and the signal
    if (distance(uv, signal) < THICKNESS)
        color = blue*intensity.y;
    else
        color = black;

    // Apply analogic effect
    analogic_screen_filter(color, uv.xy);

    fragColor = vec4(color,1.0);
}
