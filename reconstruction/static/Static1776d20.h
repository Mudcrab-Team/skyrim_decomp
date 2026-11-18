// Source exposure: binary-analysis; no external implementation source reused.
// Static1776d20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776d20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776d20*);
    virtual void release(Static1776d20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776d20*);
struct Static1776d20 {
    void* value;
    Static1776d20();
    ~Static1776d20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
