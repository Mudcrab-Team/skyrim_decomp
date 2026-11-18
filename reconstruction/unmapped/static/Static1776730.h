// Source exposure: binary-analysis; no external implementation source reused.
// Static1776730, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776730;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776730*);
    virtual void release(Static1776730*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776730*);
struct Static1776730 {
    void* value;
    Static1776730();
    ~Static1776730() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
