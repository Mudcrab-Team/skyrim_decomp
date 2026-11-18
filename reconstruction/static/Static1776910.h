// Source exposure: binary-analysis; no external implementation source reused.
// Static1776910, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776910;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776910*);
    virtual void release(Static1776910*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776910*);
struct Static1776910 {
    void* value;
    Static1776910();
    ~Static1776910() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
