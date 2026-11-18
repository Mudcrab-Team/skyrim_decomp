// Source exposure: binary-analysis; no external implementation source reused.
// Static1776dc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776dc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776dc0*);
    virtual void release(Static1776dc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776dc0*);
struct Static1776dc0 {
    void* value;
    Static1776dc0();
    ~Static1776dc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
