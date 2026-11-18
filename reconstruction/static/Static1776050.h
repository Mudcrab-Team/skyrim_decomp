// Source exposure: binary-analysis; no external implementation source reused.
// Static1776050, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776050;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776050*);
    virtual void release(Static1776050*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776050*);
struct Static1776050 {
    void* value;
    Static1776050();
    ~Static1776050() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
