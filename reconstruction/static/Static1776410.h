// Source exposure: binary-analysis; no external implementation source reused.
// Static1776410, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776410;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776410*);
    virtual void release(Static1776410*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776410*);
struct Static1776410 {
    void* value;
    Static1776410();
    ~Static1776410() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
