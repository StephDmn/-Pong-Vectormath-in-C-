VectorMath + Pong (C++ and Unity)
Overview

This project implements a custom vector mathematics library in C++ and integrates it into Unity using a DLL. The goal is to demonstrate understanding of vector operations, testing, and cross-language integration by building a functional Pong game using only custom math.

Features

Custom Vec2 and Vec3 implementation in C++

Core operations:

Add

Subtract

Scale

Dot product

Magnitude

Normalize

Cross product (Vec3)

Additional functions:

VectorReflect

VectorLerp

Console-based testing system with:

PASS and FAIL output

Edge case validation

Floating-point epsilon comparison

DLL integration between C++ and Unity

Pong game implemented in Unity using:

Custom vector math only

Manual movement and collision

No Unity physics system

Score system with UI

Project Structure

VectorLib
Contains the core vector math implementation

Vec2.h / Vec2.cpp

Vec3.h / Vec3.cpp

ConsoleTests
Used to validate all functionality before Unity integration

ConsoleTests.cpp

InteropDLL
Handles communication between C++ and Unity

Exposes C-style API using extern "C"

Uses POD structs for compatibility

Unity Project (Pong-VectorMath)

Assets/Plugins/x86_64 contains the DLL

C# scripts use DllImport to call C++ functions

How It Works

Vector operations are implemented in C++ inside VectorLib.

ConsoleTests validates all functionality independently.

InteropDLL exposes functions using a C-compatible interface.

Unity imports the DLL and calls functions via DllImport.

All gameplay math in Pong uses the custom vector system.

Example

C++ (DLL side):

Vec2_I Vec2_Add(Vec2_I a, Vec2_I b);

C# (Unity side):

[DllImport("InteropDLL")]
public static extern Vec2_I Vec2_Add(Vec2_I a, Vec2_I b);
Requirements

Visual Studio (C++ development)

Unity (Windows, x64)

Platform target must be x64

DLL must be placed in:
Assets/Plugins/x86_64/

Build Instructions

Open the solution in Visual Studio

Build the InteropDLL project in x64 configuration

Copy the generated DLL to:
Assets/Plugins/x86_64/ in Unity

Open the Unity project

Run the scene

Design Decisions

No use of UnityEngine.Vector2 to meet assignment requirements

No Unity physics system used

Manual collision and movement for full control

Separation between core math, testing, interop, and gameplay

Testing

20 total tests

All passing

Includes edge cases such as:

Zero vector normalization

Floating-point precision

Parallel vector cross product

Lerp bounds

Known Issues

Initial setup may require correct include path configuration in Visual Studio

Precompiled headers may need to be disabled or configured properly

Unity requires correct plugin folder structure to detect the DLL

Future Improvements

More advanced gameplay behavior

Additional vector operations

Improved abstraction layer on the Unity side

Expanded test coverage

Personal Note

I am terrible play my own game and have zero coordination.
