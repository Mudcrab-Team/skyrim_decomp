// Source exposure: binary-analysis; no external implementation source reused.
// Static1776000, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776000;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776000*);
    virtual void release(Static1776000*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776000*);
struct Static1776000 {
    void* value;
    Static1776000();
    ~Static1776000() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
