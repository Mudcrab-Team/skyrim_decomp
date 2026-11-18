// Source exposure: binary-analysis; no external implementation source reused.
// Static1776550, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776550;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776550*);
    virtual void release(Static1776550*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776550*);
struct Static1776550 {
    void* value;
    Static1776550();
    ~Static1776550() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
