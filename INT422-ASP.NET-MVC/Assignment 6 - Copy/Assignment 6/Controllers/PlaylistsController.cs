using AutoMapper;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment_6.Controllers
{
    public class PlaylistsController : Controller
    {
        Manager m = new Manager();
        // GET: Playlists
        public ActionResult Index()
        {
            return View(m.PlaylistWithTracksGetAll());
        }

        // GET: Playlists/Details/5
        public ActionResult Details(int? id)
        {
            var o = m.PlaylistWithTracksGetById(id.GetValueOrDefault());

            if (o == null)
            {
                return HttpNotFound();
            }
            else
            {
                return View(o);
            }
        }

        // GET: Playlists/Create
        /**
        public ActionResult Create()
        {
            return View();
        }

        // POST: Playlists/Create
        [HttpPost]
        public ActionResult Create(FormCollection collection)
        {
            try
            {
                // TODO: Add insert logic here

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }
        */
        // GET: Playlists/Edit/5
        public ActionResult Edit(int? id)
        {
            var o = m.PlaylistWithTracksGetById(id.GetValueOrDefault());


            if (o == null)
            {
                return HttpNotFound();
            }
            else
            {
                var form = Mapper.Map<PlaylistBase, PlaylistEditTracksForm>(o);
                form.Tracks = o.Tracks.OrderBy(n => n.Name);
                var selectedValues = o.Tracks.Select(t => t.TrackId);
                form.TrackList = new MultiSelectList(
                                        items: m.TrackGetAll(),
                                        dataValueField: "TrackId",
                                        dataTextField: "FullName",
                                        selectedValues: selectedValues);

                return View(form);
            }

        }

        // POST: Playlists/Edit/5
        [HttpPost]
        public ActionResult Edit(int? id, PlaylistEditTracks newItem)
        {
            if (!ModelState.IsValid)
            {

                return RedirectToAction("edit", new { id = newItem.PlaylistId });
            }

            if (id.GetValueOrDefault() != newItem.PlaylistId)
            {
                return RedirectToAction("index");
            }

            var editedItem = m.PlaylistEditTracks(newItem);

            if (editedItem == null)
            {
                return RedirectToAction("edit", new { id = newItem.PlaylistId });
            }
            else
            {

                return RedirectToAction("details", new { id = newItem.PlaylistId });
            }

        }

        // GET: Playlists/Delete/5

    }
}