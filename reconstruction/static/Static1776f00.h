// Source exposure: binary-analysis; no external implementation source reused.
// Static1776f00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776f00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776f00*);
    virtual void release(Static1776f00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776f00*);
struct Static1776f00 {
    void* value;
    Static1776f00();
    ~Static1776f00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
