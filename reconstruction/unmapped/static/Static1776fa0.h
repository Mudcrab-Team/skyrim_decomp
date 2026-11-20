// Source exposure: binary-analysis; no external implementation source reused.
// Static1776fa0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776fa0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776fa0*);
    virtual void release(Static1776fa0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776fa0*);
struct Static1776fa0 {
    void* value;
    Static1776fa0();
    ~Static1776fa0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
