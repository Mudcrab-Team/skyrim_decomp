// Source exposure: binary-analysis; no external implementation source reused.
// Static1776190, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776190;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776190*);
    virtual void release(Static1776190*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776190*);
struct Static1776190 {
    void* value;
    Static1776190();
    ~Static1776190() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
