// Source exposure: binary-analysis; no external implementation source reused.
// Static1776aa0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776aa0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776aa0*);
    virtual void release(Static1776aa0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776aa0*);
struct Static1776aa0 {
    void* value;
    Static1776aa0();
    ~Static1776aa0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
