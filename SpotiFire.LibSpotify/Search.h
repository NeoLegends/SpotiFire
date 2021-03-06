// Search.h

#pragma once
#include "Stdafx.h"

using namespace System;
using namespace System::Collections::Generic;

namespace SpotiFire {
	ref class Link;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Search. </summary>
	///
	/// <remarks>	Aleksander, 03.02.2013. </remarks>
	///-------------------------------------------------------------------------------------------------
	public ref class Search sealed : ISpotifyObject, ISpotifyAwaitable<Search ^>
	{
	private:
		IList<Track ^> ^_tracks;
		IList<Album ^> ^_albums;
		IList<Playlist ^> ^_playlists;
		IList<Artist ^> ^_artists;

		volatile bool _complete;
		TaskCompletionSource<Search ^> ^_tcs;

	internal:
		Session ^_session;
		sp_search *_ptr;

		Search(Session ^session, sp_search *ptr);
		!Search(); // finalizer
		~Search(); // destructor

	public:

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Gets the session. </summary>
		///
		/// <value>	The session. </value>
		///-------------------------------------------------------------------------------------------------
		virtual property Session ^Session { SpotiFire::Session ^get() sealed; }

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Gets a value indicating whether this object is loaded. </summary>
		///
		/// <value>	true if this object is loaded, false if not. </value>
		///-------------------------------------------------------------------------------------------------
		virtual property bool IsLoaded { bool get() sealed; }

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Gets the error. </summary>
		///
		/// <value>	The error. </value>
		///-------------------------------------------------------------------------------------------------
		virtual property Error Error { SpotiFire::Error get() sealed; }

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Gets the query. </summary>
		///
		/// <value>	The query. </value>
		///-------------------------------------------------------------------------------------------------
		virtual property String ^Query { String ^get() sealed; }

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Gets the did you mean. </summary>
		///
		/// <value>	The did you mean. </value>
		///-------------------------------------------------------------------------------------------------
		virtual property String ^DidYouMean { String ^get() sealed; }

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Gets the tracks. </summary>
		///
		/// <value>	The tracks. </value>
		///-------------------------------------------------------------------------------------------------
		virtual property IList<Track ^> ^Tracks { IList<Track ^> ^get() sealed; }

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Gets the albums. </summary>
		///
		/// <value>	The albums. </value>
		///-------------------------------------------------------------------------------------------------
		virtual property IList<Album ^> ^Albums { IList<Album ^> ^get() sealed; }

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Gets the playlists. </summary>
		///
		/// <value>	The playlists. </value>
		///-------------------------------------------------------------------------------------------------
		virtual property IList<Playlist ^> ^Playlists { IList<Playlist ^> ^get() sealed; }

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Gets the artists. </summary>
		///
		/// <value>	The artists. </value>
		///-------------------------------------------------------------------------------------------------
		virtual property IList<Artist ^> ^Artists { IList<Artist ^> ^get() sealed; }

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Gets the total tracks. </summary>
		///
		/// <value>	The total number of tracks. </value>
		///-------------------------------------------------------------------------------------------------
		virtual property int TotalTracks { int get() sealed; }

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Gets the total albums. </summary>
		///
		/// <value>	The total number of albums. </value>
		///-------------------------------------------------------------------------------------------------
		virtual property int TotalAlbums { int get() sealed; }

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Gets the total playlists. </summary>
		///
		/// <value>	The total number of playlists. </value>
		///-------------------------------------------------------------------------------------------------
		virtual property int TotalPlaylists { int get() sealed; }

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Gets the total artists. </summary>
		///
		/// <value>	The total number of artists. </value>
		///-------------------------------------------------------------------------------------------------
		virtual property int TotalArtists { int get() sealed; }

		///-------------------------------------------------------------------------------------------------
		/// <summary>   Create a <see cref="SpotiFire.Link"/> object representing the search. </summary>
		///
		/// <remarks>   You need to Dispose the <see cref="SpotiFire.Link"/> object when you are done with
		///				it. </remarks>
		///
		/// <returns>	A <see cref="SpotiFire.Link"/> object representing this search. </returns>
		///-------------------------------------------------------------------------------------------------
		virtual Link ^GetLink();

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Gets the hash code for this search object. </summary>
		///
		/// <remarks>	Chris Brandhorst, 16.05.2013. </remarks>
		///
		/// <returns>	The hash code. </returns>
		///-------------------------------------------------------------------------------------------------
		virtual int GetHashCode() override;

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Checks if this search object is considered to be the same as the given object.
		///				</summary>
		///
		/// <remarks>	Chris Brandhorst, 16.05.2013. </remarks>
		///
		/// <param name="other">	The object to compare. </param>
		///
		/// <returns>	true if the given object is equal to the search object, otherwise false.
		///				</returns>
		///-------------------------------------------------------------------------------------------------
		virtual bool Equals(Object ^other) override;

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Checks if the given search objects should be considered equal. </summary>
		///
		/// <remarks>	Chris Brandhorst, 16.05.2013. </remarks>
		///
		/// <param name="left">	The search object on the left-hand side of the operator. </param>
		/// <param name="right">	The search object on the right-hand side of the operator. </param>
		///
		/// <returns>	true if the given searches are equal, otherwise false. </returns>
		///-------------------------------------------------------------------------------------------------
		static bool operator== (Search ^left, Search ^right);

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Checks if the given search objects should not be considered equal. </summary>
		///
		/// <remarks>	Chris Brandhorst, 16.05.2013. </remarks>
		///
		/// <param name="left">	The search object on the left-hand side of the operator. </param>
		/// <param name="right">	The search object on the right-hand side of the operator. </param>
		///
		/// <returns>	true if the given search objects are not equal, otherwise false. </returns>
		///-------------------------------------------------------------------------------------------------
		static bool operator!= (Search ^left, Search ^right);

	public:
		virtual System::Runtime::CompilerServices::TaskAwaiter<Search ^> GetAwaiter() sealed = ISpotifyAwaitable<Search ^>::GetAwaiter;

	internal:
		static Search ^Create(SpotiFire::Session ^session, String ^query, int trackOffset, int trackCount, int albumOffset, int albumCount, int artistOffset, int artistCount, int playlistOffset, int playlistCount, SearchType type);

		// Spotify events
		void complete();
	};
}