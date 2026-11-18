// Source exposure: binary-analysis; no external implementation source reused.
// Static1776c30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776c30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776c30*);
    virtual void release(Static1776c30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776c30*);
struct Static1776c30 {
    void* value;
    Static1776c30();
    ~Static1776c30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
