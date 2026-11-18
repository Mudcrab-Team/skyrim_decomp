// Source exposure: binary-analysis; no external implementation source reused.
// Static1776780, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776780;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776780*);
    virtual void release(Static1776780*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776780*);
struct Static1776780 {
    void* value;
    Static1776780();
    ~Static1776780() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
