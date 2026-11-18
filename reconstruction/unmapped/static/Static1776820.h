// Source exposure: binary-analysis; no external implementation source reused.
// Static1776820, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776820;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776820*);
    virtual void release(Static1776820*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776820*);
struct Static1776820 {
    void* value;
    Static1776820();
    ~Static1776820() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
