// Source exposure: binary-analysis; no external implementation source reused.
// Static1776320, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776320;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776320*);
    virtual void release(Static1776320*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776320*);
struct Static1776320 {
    void* value;
    Static1776320();
    ~Static1776320() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
