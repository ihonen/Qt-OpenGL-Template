#pragma once

struct Renderer;

struct Renderer* Renderer_new();
void Renderer_init(struct Renderer* self);
void Renderer_free(struct Renderer* self);

void Renderer_doRender(struct Renderer* self);
void Renderer_setViewPort(struct Renderer* self, int x, int y, int w, int h);
