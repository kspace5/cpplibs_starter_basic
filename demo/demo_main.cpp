
#include <vector>
#include <string>
#include "xyc_utils.h"
#include "abc_utils.h"
#include <iostream>

#include "NvFlex.h"
#include "NvFlexExt.h"
#include "NvFlexDevice.h"
#include "glm/vec4.hpp"
#include "glm/vec3.hpp"
#include <glm/gtx/string_cast.hpp>

std::string helloString(std::string str)
{
	return "Hello world " + str;
}

using namespace std;

void doFlex() {
    bool done = false;
    int n = 100;
    float dt = 1.0f / 60.0f;

    NvFlexLibrary* library = NvFlexInit();

    // create new solver
    NvFlexSolverDesc solverDesc;
    NvFlexSetSolverDescDefaults(&solverDesc);
    solverDesc.maxParticles = n;
    solverDesc.maxDiffuseParticles = 0;

    NvFlexSolver* solver = NvFlexCreateSolver(library, &solverDesc);

    NvFlexBuffer* particleBuffer = NvFlexAllocBuffer(library, n, sizeof(glm::vec4), eNvFlexBufferHost);
    NvFlexBuffer* velocityBuffer = NvFlexAllocBuffer(library, n, sizeof(glm::vec4), eNvFlexBufferHost);
    NvFlexBuffer* phaseBuffer = NvFlexAllocBuffer(library, n, sizeof(int), eNvFlexBufferHost);

    int i = 0;
    while (!done)
    {
        // map buffers for reading / writing
        glm::vec4* particles = (glm::vec4*)NvFlexMap(particleBuffer, eNvFlexMapWait);
        glm::vec3* velocities = (glm::vec3*)NvFlexMap(velocityBuffer, eNvFlexMapWait);
        int* phases = (int*)NvFlexMap(phaseBuffer, eNvFlexMapWait);

        // spawn (user method)
        //SpawnParticles(particles, velocities, phases);

        // render (user method)
        //RenderParticles(particles, velocities, phases);

        // unmap buffers
        NvFlexUnmap(particleBuffer);
        NvFlexUnmap(velocityBuffer);
        NvFlexUnmap(phaseBuffer);

        // write to device (async)
        NvFlexSetParticles(solver, particleBuffer, NULL);
        NvFlexSetVelocities(solver, velocityBuffer, NULL);
        NvFlexSetPhases(solver, phaseBuffer, NULL);

        // tick
        NvFlexUpdateSolver(solver, dt, 1, false);

        // read back (async)
        NvFlexGetParticles(solver, particleBuffer, NULL);
        NvFlexGetVelocities(solver, velocityBuffer, NULL);
        NvFlexGetPhases(solver, phaseBuffer, NULL);

        if (i % 60 == 0) {
            std::cout << glm::to_string(particles[0]) << std::endl;
        }

        if (++i == 200) break;
    }

    NvFlexFreeBuffer(particleBuffer);
    NvFlexFreeBuffer(velocityBuffer);
    NvFlexFreeBuffer(phaseBuffer);

    NvFlexDestroySolver(solver);
    NvFlexShutdown(library);
}

// int main( int argc, const char* argv[] )
int main()
{
    std::cout << helloString("Earth") << endl;
	auto ivec1 = abc::split_to_ints("12|2343|23434", '|');
	auto ivec2 = xyc::split_to_ints("23|101230|-23", '|');
	for (int v : ivec1) {
		cout << "From static lib:" << v << endl;
	}
	for (int v : ivec2) {
		cout << "From dynamic lib:" << v << endl;
	}
    doFlex();
}

