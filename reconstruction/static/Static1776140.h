// Source exposure: binary-analysis; no external implementation source reused.
// Static1776140, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776140;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776140*);
    virtual void release(Static1776140*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776140*);
struct Static1776140 {
    void* value;
    Static1776140();
    ~Static1776140() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
