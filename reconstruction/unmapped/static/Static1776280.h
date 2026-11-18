// Source exposure: binary-analysis; no external implementation source reused.
// Static1776280, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776280;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776280*);
    virtual void release(Static1776280*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776280*);
struct Static1776280 {
    void* value;
    Static1776280();
    ~Static1776280() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
