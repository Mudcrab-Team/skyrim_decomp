// Source exposure: binary-analysis; no external implementation source reused.
// Static1776b90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776b90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776b90*);
    virtual void release(Static1776b90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776b90*);
struct Static1776b90 {
    void* value;
    Static1776b90();
    ~Static1776b90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
